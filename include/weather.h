#include <Arduino.h>
#include <Arduino_JSON.h>
#include <HTTPClient.h>

// String serverName = "dmigw.govcloud.dk/";
// String serviceVersion = "v1/";
// String serviceName = "forecastdata/";
// String collection = "harmonie_nea_sf/";

// String APIkey = "vd29330d5-b7ac-480b-a940-5e49442bc1e3";

// String baseRequest = serverName + serviceVersion + serviceName + "/collections"+collection + "items";

String getWeatherRequest(String baseRequest);
void parseWeatherRequest (String baseRequest);