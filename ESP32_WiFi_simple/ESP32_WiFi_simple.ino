/*
  cannot get this to run @ 6th july 2018 ugh.     ???

 Simple web server to show values of analog input pins. 
 Modified to run on ESP-WROOM-32
 
 github.com/aspiringguru
 @aspiringguru

  GPIO ADC Channel
  
  GPIO 0 ==> ADC2_CH1
  GPIO 2 ==> ADC2_CH2
  GPIO 4 ==> ADC2_CH0
  GPIO 12 => ADC2_CH5
  GPIO 13 => ADC2_CH4
  GPIO 14 => ADC2_CH6
  GPIO 15 => ADC2_CH3
  GPIO 25 => ADC2_CH8
  GPIO 26 => ADC2_CH9
  GPIO 27 => ADC2_CH7
  GPIO 32 => ADC1_CH4
  GPIO 33 => ADC1_CH5
  GPIO 34 => ADC1_CH6
  GPIO 35 => ADC1_CH7
  GPIO 36 => ADC1_CH0
  GPIO 37 => ADC1_CH1
  GPIO 38 => ADC1_CH2
  GPIO 39 => ADC1_CH3

 */

#include <SPI.h>
#include <WiFi.h>


char ssid[] = "sleepyPluto";      // your network SSID (name)
char pass[] = "rfv45891";         // your network password
int keyIndex = 0;                 // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;

WiFiServer server(80);

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }



  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 3 seconds for connection:
    delay(3000);
  }
  server.begin();
  // you're connected now, so print out the status:
  printWifiStatus();
}


void loop() {
  // listen for incoming clients
  Serial.println("inside loop");
  delay(500);
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
}

