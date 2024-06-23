#include "WebServerManager.h"

WebServerManager::WebServerManager() : server(80){}

void WebServerManager::begin(){
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SD, "/site/index.html", "text/html");
    });

    server.on("/bs/css/bootstrap.min.css", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SD, "/site/bs/css/bootstrap.min.css", "text/css");
    });

    server.on("/css/styles.css", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SD, "/site/css/styles.css", "text/css");
    });

    server.on("/bs/js/bootstrap.bundle.min.js", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SD, "/site/bs/js/bootstrap.bundle.min.js", "application/javascript");
    });

    server.on("/js/main.js", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SD, "/site/js/main.js", "application/javascript");
    });

    server.begin();
}