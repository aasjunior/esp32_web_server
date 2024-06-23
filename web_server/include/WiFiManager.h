#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFi.h>
#include "Enums.h"

class WiFiManager{
public:
    WiFiManager(const char* ssid, const char* password);
    WiFiStatus connect();
    IPAddress getIP();

private:
    const char* ssid;
    const char* password;
};

#endif