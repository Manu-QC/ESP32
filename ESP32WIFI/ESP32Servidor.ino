#include <WiFi.h>

const char* ssid = "Redmi Note 11S";
const char* password = "123456789";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conectado a WiFi!");
}

void loop() {}
