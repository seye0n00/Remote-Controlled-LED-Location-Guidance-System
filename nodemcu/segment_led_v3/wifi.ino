
#include <ESP8266WiFi.h>
#include "log.h"
#include "config.h"

void setup_wifi() {
  LOG_I("WIFI", "Connecting to WiFi...");
  
  delay(10);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  int retry = 0;

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    retry++;
    if(retry > 20){
      LOG_W("WIFI", "Connecting is taking longer than expected");
      //return;
    }
  }
  
  LOG_I("WIFI", "Connected");
  LOG_I("WIFI", WiFi.localIP().toString());

}