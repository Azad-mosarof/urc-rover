// #include <SoftwareSerial.h>
// #include <ESP8266WiFi.h>

// SoftwareSerial NodeMCU(D2,D3);

// void setup(){
// 	Serial.begin(9600);
// 	NodeMCU.begin(4800);
// 	pinMode(D2,INPUT);
// 	pinMode(D3,OUTPUT);
// }

// void loop(){
// 	int i = Serial.parseInt();
// 	NodeMCU.print(i);
// 	NodeMCU.println("\n");
// }

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define WIFI_SSID "vivo14"
#define WIFI_PSWD "123456789"

ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PSWD);
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  Serial.println(" .....");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(600);
    i++;
    Serial.print(i);
    Serial.print(" ");
  }
  Serial.println(" ");
  Serial.println("Connected: ");
  Serial.print("Ip Address:  ");
  Serial.println(WiFi.localIP());
  Serial.println();

  server.on("/send", HTTP_GET, []() {
    if (server.hasArg("data")) {
      String data = server.arg("data");
      Serial.print("Received data: ");
      Serial.println(data);
      server.send(200, "text/plain", "Data received");
    } else {
      server.send(400, "text/plain", "Bad Request");
    }
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
