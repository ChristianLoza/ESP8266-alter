#ifndef WIFI_H
#define WIFI_H

#include "Arduino.h"
#include "SoftwareSerial.h"


class WifiClass {
    public:
        WifiClass();
        void setup();
        void connect(String ssid, String password);
        void http(String server, String uri, String data);
    private:
        void reset();
};

extern WifiClass Wifi;

#endif
