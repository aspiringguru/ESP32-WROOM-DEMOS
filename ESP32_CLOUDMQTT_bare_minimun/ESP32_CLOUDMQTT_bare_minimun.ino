#include <WiFi.h>
#include <PubSubClient.h>

#define wifi_ssid "sleepyVenus"
#define wifi_password "Qazwsx123"

#define mqtt_server "m13.cloudmqtt.com"
#define mqtt_port 38269
#define mqtt_user "vrjnymof"
#define mqtt_password "c3-rGW-ASgJh"

#define in_topic "/light/in"
#define out_topic "/light/out"
// Replace by 2 if you aren't enable to use Serial Monitor... Don't forget to Rewire R1 to GPIO2!
#define in_led 2

WiFiClient espClient;
PubSubClient client;

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setClient(espClient);
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(in_led, OUTPUT);
  digitalWrite(in_led, HIGH);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);

  WiFi.begin(wifi_ssid, wifi_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    // If you do not want to use a username and password, change next line to
    // if (client.connect("ESP8266Client")) {
    if (client.connect("ESP8266Client", mqtt_user, mqtt_password)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
 Serial.print("Message arrived [");
 Serial.print(topic);
 Serial.print("] ");
 for (int i = 0; i < length; i++) {
  char receivedChar = (char)payload[i];
  Serial.print(receivedChar);
  if (receivedChar == '0')
   digitalWrite(in_led, LOW);
  if (receivedChar == '1')
   digitalWrite(in_led, HIGH);
 }
 Serial.println();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  // Publishes a random 0 and 1 like someone switching off and on randomly (random(2))
  client.publish(out_topic, String(random(2)).c_str(), true);
  delay(1000);
  client.subscribe(in_topic);
  delay(1000);
}
