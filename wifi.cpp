#include "wifi.h"

String server2 = "atencionbombero.disce.me";
String uri2 = "/CategoriaAtencion";
String data2 = "{\"categoria\":\"Arduino\", \"descripcion\": \"Prueba\", \"estado\": 1}";

SoftwareSerial esp(8, 9);

WifiClass::WifiClass() {

}

void WifiClass::setup() {
  esp.begin(115200);
  reset();
}

void WifiClass::connect(String ssid, String password) {
  String cmd = "AT+CWJAP=\"" +ssid+"\",\"" + password + "\"";
  esp.println(cmd);
  delay(4000);
  if(esp.find("OK")) {
    Serial.println("Connected!");
  } else {
    connect(ssid, password);
    Serial.println("Cannot connect to wifi");
  }
}

void WifiClass::http(String server, String uri, String data) {
  esp.println("AT+CIPSTART=\"TCP\",\"" + server + "\",8080");//start a TCP connection.

  if( esp.find("OK")) {
    Serial.println("TCP connection ready");
  }

  delay(1000);

  String postRequest =
  "POST " + uri + " HTTP/1.1\r\n" +
  "Host: " + server + "\r\n" +
  "Accept: *" + "/" + "*\r\n" +
  "Content-Length: " + data.length() + "\r\n" +
  "Content-Type: application/json\r\n" +
  "\r\n" + data;

  String sendCmd = "AT+CIPSEND=";//determine the number of caracters to be sent.

  esp.print(sendCmd);
  esp.println(postRequest.length() );

  delay(500);

  if(esp.find(">")) {
    Serial.println("Sending.."); esp.print(postRequest);

    if( esp.find("SEND OK")) {
      Serial.println("Packet sent");

      while (esp.available()) {
        String tmpResp = esp.readString();
        Serial.println(tmpResp);
      }

      esp.println("AT+CIPCLOSE");
    }
  }
}

void WifiClass::reset() {
  esp.println("AT+RST");
  delay(1000);
  if(esp.find("OK")) Serial.println("Module Reset");
}

WifiClass Wifi = WifiClass();
