#include "wifi.h"

String server = "http://127.0.1.1";
String uri = "/master_path/getData";
String data = "{\"value\":\"object\"}";
void setup() {
  Serial.begin(9600);
  Wifi.setup();
  Wifi.connect("SSID", "password SSID");
}

void loop() {
  Wifi.http(server, uri, data);
}


