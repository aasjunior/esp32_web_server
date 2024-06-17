#include <WiFi.h>
#include <WebServer.h>
#include "credentials.h"
#include "index_html.h"

WebServer server(80);

void setup() {
    Serial.begin(9600);

    // Conectar ao WiFi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Conectando ao WiFi...");
    }
    Serial.println("Conectado ao WiFi!");
    Serial.print("Endereço IP: ");
    Serial.println(WiFi.localIP());

    // Configurar rota para servir a página web
    server.on("/", HTTP_GET, [](){
        server.send_P(200, "text/html", index_html);
    });

    // Iniciar servidor web
    server.begin();
    Serial.println("Servidor web iniciado");
}

void loop() {
    server.handleClient();
}
