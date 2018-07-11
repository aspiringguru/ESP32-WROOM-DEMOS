#include <WiFi.h>
 
const char *ssid = "sleepyMoon";
const char *password = "rfv45891";
 
void setup() {
 
  Serial.begin(115200);
WiFi.softAP(ssid, password);
 
  Serial.println();
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
 
}
 
void loop() {}
