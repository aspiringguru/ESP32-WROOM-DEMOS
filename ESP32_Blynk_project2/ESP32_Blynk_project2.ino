#define BLYNK_PRINT Serial

int pin        = 4;

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "318760ee7c6144779c596901da15e637";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "sleepyVenus";
char pass[] = "Qazwsx123";

void setup() {
  pinMode(pin, OUTPUT);
  pinMode(pin, HIGH);
  Serial.begin(115200);

  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);
  int wifi_ctr = 0;
  Serial.println("Connecting to WiFi.");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
  Serial.println((String)"local ip#:"+WiFi.localIP());

  Blynk.begin("318760ee7c6144779c596901da15e637", ssid, pass);

}

void loop(){
    Blynk.run();
}
