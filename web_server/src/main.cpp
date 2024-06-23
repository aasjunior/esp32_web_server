#include <Arduino.h>
#include "WiFiManager.h"
#include "SDManager.h"
#include "WebServerManager.h"
#include "Credentials.h"

const int SD_CS_PIN = 5;

WiFiManager wifiManager(ssid, password);
SDManager sdManager(SD_CS_PIN);
WebServerManager webServerManager;

void setup() {
  Serial.begin(115200);

  if(wifiManager.connect() == WIFI_CONNECTED){
    Serial.print("IP address: ");
    Serial.println(wifiManager.getIP());
  }

  if(sdManager.begin() == SD_INITIALIZED){
    sdManager.listDir(SD, "/", 3);
  }

  webServerManager.begin();
}

void loop() {
  // Nada a fazer no loop
}
