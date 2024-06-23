#include "WiFiManager.h"

WiFiManager::WiFiManager(const char* ssid, const char* password)
    : ssid(ssid), password(password){}

WiFiStatus WiFiManager::connect(){
    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED){
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    if(WiFi.status() == WL_CONNECTED){
        Serial.println("Connected to WiFi!");
        return WIFI_CONNECTED;
    }else{
        Serial.println("WiFi connection failed!");
        return WIFI_FAILED;
    }
}

IPAddress WiFiManager::getIP(){
    return WiFi.localIP();
}