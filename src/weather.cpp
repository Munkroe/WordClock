#include "weather.h"

String getWeatherRequest(String baseRequest) {
  HTTPClient http;

  // Your IP address with path or Domain name with URL path 
  http.begin(baseRequest);

  // Send HTTP POST request
  int httpResponseCode = http.GET();

  String payload = "{}"; 

  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}

void parseWeatherRequest (String baseRequest) {
    
    JSONVar myObject = JSON.parse(getWeatherRequest(baseRequest).c_str());

if (JSON.typeof(myObject) == "undefined") {
  Serial.println("Parsing weather failed!");
}
Serial.print("JSON object = ");
Serial.println(myObject);
return;
}
