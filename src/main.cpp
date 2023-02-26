#include <Arduino.h>
#include <ezTime.h>
#include <WiFi.h>
#include "clock.h"
#include "weather.h"

String baseRequest = "http://vejr.eu/api.php?location=Aalborg&degree=C";

void setup() {
  
	Serial.begin(9600);
	while (!Serial) { ; }		// wait for Serial port to connect. Needed for native USB port only
  while (WiFi.status() != WL_CONNECTED) {  //If WiFi is not connected, try again after 1 second
    Serial.println("WL not connected, trying again...");
	  WiFi.begin("Munkerens Palads", "Munkeren");
    delay(1000);
  }
	waitForSync();
	Timezone myTZ;
	myTZ.setLocation(F("dk"));
	Serial.print(F("Denmark:         "));
	Serial.println(myTZ.dateTime());
  Serial.println(myTZ.minute()); //If you dont use myTZ, then it will default to CET. 
  Serial.println(convertDanishTime(myTZ.hour(), myTZ.minute()));
}

void loop() {
	
  if (minuteChanged()){
    Serial.println(convertDanishTime(hour()+1, minute()));
  }
  parseWeatherRequest(baseRequest);
  delay(5000);
  //events();
}