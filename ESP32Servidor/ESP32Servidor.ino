#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Redmi Note 11S";
const char* pass = "123456789";

WebServer server(80);

void handleRoot() {
  String html = R"rawliteral(
  <!DOCTYPE html>
  <html>
  <head>
    <meta charset="UTF-8">
    <title>Información ESP32</title>
    <style>
      body {
        background: #f4f4f4;
        font-family: Arial, sans-serif;
        display: flex;
        justify-content: center;
        align-items: center;
        height: 100vh;
        margin: 0;
      }
      .card {
        background: white;
        padding: 30px;
        border-radius: 15px;
        box-shadow: 0px 4px 12px rgba(0,0,0,0.2);
        text-align: center;
        max-width: 350px;
      }
      h1 {
        color: #800000; /* granate */
        margin-bottom: 10px;
      }
      p {
        font-size: 18px;
        margin: 8px 0;
      }
      .footer {
        margin-top: 15px;
        font-size: 14px;
        color: #555;
      }
    </style>
  </head>
  <body>
    <div class="card">
      <h1>ESP32 Web Server</h1>
      <p><strong>Nombre:</strong><br>Manuel Eduardo Quispe Condori</p>
      <p><strong>Código:</strong><br>200858</p>
      <div class="footer">Conectado a WiFi</div>
    </div>
  </body>
  </html>
  )rawliteral";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  Serial.print("Conectando a WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado! IP: " + WiFi.localIP().toString());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("Servidor web iniciado.");
}

void loop() {
  server.handleClient();
}
