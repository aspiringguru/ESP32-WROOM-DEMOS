#include <WiFi.h>
#include <PubSubClient.h>
 
const char* ssid = "sleepyVenus";
const char* password =  "Qazwsx123";
//get server/port/user/password from https://api.cloudmqtt.com/console/9850309/details
const char* mqttServer = "m13.cloudmqtt.com";
const int mqttPort = 12564;
const char* mqttUser = "Matthew1";
const char* mqttPassword = "mqttPlmokn789";
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
 
  Serial.begin(115200);
  Serial.println("setup start");
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    Serial.println((String)"mqttUser: "+mqttUser);
    Serial.println((String)"mqttPassword : "+mqttPassword );
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.println(client.state());
      delay(2000);
 
    }
  }
 
  client.publish("esp/test", "Hello from ESP8266");
  client.subscribe("esp/test");
 
}
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
 
  Serial.println();
  Serial.println("-----------------------");
 
}
 
void loop() {
  client.loop();
}
