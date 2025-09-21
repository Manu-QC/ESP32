#include <WiFi.h>
const char* ssid = "Redmi Note 11S";
const char* pass = "123456789";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  Serial.print("Conectando");
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.println("\nConectado! IP: " + WiFi.localIP().toString());
}
void loop(){}
