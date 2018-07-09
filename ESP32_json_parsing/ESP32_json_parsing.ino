#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// WiFi Parameters
//import sensitive data from external file, set gitignore to exclude the external file
#include "settings.h" 
const char* ssid = MY_WIFI_SSID;
const char* password =  MY_WIFI_PASSWORD;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
}

void loop() {
  // Check WiFi Status
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;  //Object of class HTTPClient
    http.begin("http://jsonplaceholder.typicode.com/users/1");
    int httpCode = http.GET();
    //Check the returning code                                                                  
    if (httpCode > 0) {
      // Parsing
      const size_t bufferSize = JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(8) + 370;
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(http.getString());
      // Parameters
      int id = root["id"]; // 1
      const char* name = root["name"]; // "Leanne Graham"
      const char* username = root["username"]; // "Bret"
      const char* email = root["email"]; // "Sincere@april.biz"
      // Output to serial monitor
      Serial.print("Name:");
      Serial.println(name);
      Serial.print("Username:");
      Serial.println(username);
      Serial.print("Email:"); 
      Serial.println(email);
    }
    http.end();   //Close connection
  }
  // Delay
  delay(60000);
}
