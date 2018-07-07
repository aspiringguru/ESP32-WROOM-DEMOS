#include <SPI.h>
#include <WiFi.h>

//const char* ssid = "sleepyPluto";
//const char* password =  "rfv45891";

char ssid[] = "sleepyPluto";      //  your network SSID (name)
char pass[] = "rfv45891";   // your network password

int status = WL_IDLE_STATUS;

const uint16_t port = 8090;
const char * host = "192.168.1.103";
//above is ip for server. initially testing on server on local network
// later host will be in cloud.

void setup()
{
  Serial.begin(115200);
  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);                   // print the network name (SSID);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);
    // wait for connection:
    delay(5000);
  }
  printWifiStatus();                        // you're connected now, so print out the status
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
    WiFiClient client;

    if (!client.connect(host, port)) {

        Serial.println("Connection to host failed");

        delay(1000);
        return;
    }

    Serial.println("Connected to server successful!");

    client.print("Hello from ESP32!");

    Serial.println("Disconnecting...");
    client.stop();

    delay(10000);
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}

