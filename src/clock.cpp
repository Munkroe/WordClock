#include <Arduino.h>
#include "clock.h"

String updateClock (String currentTime) {

return currentTime;
}

String convertDanishTime (uint8_t hours, uint8_t minutes) {

    bool nextHour = false;
    String danishTime = "Klokken er ";
    hours = hours % 12;

    if (minutes >= 0 and minutes < 5) {
        nextHour = false;
    }
    else if (minutes >= 5 and minutes < 10) {
        danishTime +="fem minutter over ";
        nextHour = false;
    }
    else if (minutes >= 10 and minutes < 15) {
        danishTime +="ti minutter over ";
        nextHour = false;
    }
    else if (minutes >= 15 and minutes < 20) {
        danishTime +="kvart over ";
        nextHour = false;
    }
    else if (minutes >= 20 and minutes < 25) {
        danishTime +="tyve minutter over ";
        nextHour = false;
    }
    else if (minutes >= 25 and minutes < 30) {
        danishTime +="fem minutter i halv ";
        nextHour = true;
    }   
    else if (minutes >= 30 and minutes < 35) {
        danishTime +="halv ";
        nextHour = true;
    }
    else if (minutes >= 35 and minutes < 40) {
        danishTime +="fem minutter over halv ";
        nextHour = true;
    }
    else if (minutes >= 40 and minutes < 45) {
        danishTime +="tyve minutter i ";
        nextHour = true;
    }
    else if (minutes >= 45 and minutes < 50) {
        danishTime +="kvart i ";
        nextHour = true;
    }
    else if (minutes >= 50 and minutes < 55) {
        danishTime +="ti minutter i ";
        nextHour = true;
    }
    else if (minutes >= 55 and minutes < 60) {
        danishTime +="fem minutter i ";
        nextHour = true;
    }
    
    String hoursString[13] = {
    "tolv", "et", "to", "tre", "fire", "fem", "seks", "syv", "otte", "ni", "ti", "elleve", "tolv"
    };

    if (nextHour == true) {
        hours += 1;
    }
    danishTime += hoursString[hours];

    return danishTime;
}