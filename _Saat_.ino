#include <SoftwareSerial.h>
#include "NTPClient.h"
#include "ESP8266WiFi.h"
#include "WiFiUdp.h"

const char *ssid = "Redmi12C";
const char *password = "3spqhr4mbs2kaae";

SoftwareSerial Ser(D5,D6);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  Ser.begin(9600);
  timeClient.begin();
}

void loop() {
  //timeClient.update();

  if (Ser.available() > 0) {
    String a = Ser.readString();
    int b = a.toInt();
    if (b == 255) {
      timeClient.update();
      Ser.println(timeClient.getHours() + 2);
      delay(5000);
      Ser.println(timeClient.getMinutes());
    }
  }
}
