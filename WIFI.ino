#include "wifi.h"

String server = "http://192.168.1.58";
String uri = "/registroAcademico-war/consulta/dni/getDni";
String data = "{\"dni\":\"46218219\"}";
void setup() {
  Serial.begin(9600);
  Wifi.setup();
  Wifi.connect("AequilibriumIX", "19CH2ITLa1q");
}

void loop() {
  Wifi.http(server, uri, data);
}


