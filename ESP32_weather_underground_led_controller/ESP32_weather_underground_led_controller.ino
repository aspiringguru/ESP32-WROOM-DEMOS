#include <WiFi.h>
#include <HTTPClient.h>

//import sensitive data from external file, set gitignore to exclude the external file
#include "settings.h" 
const char* ssid = MY_WIFI_SSID;
const char* password =  MY_WIFI_PASSWORD;


const String endpoint = MY_ENDPOINT;
const String key = MY_API_KEY;
 
void setup() {
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
  //Serial.println((String)"Connecting to WiFi.. SSID:"+ssid+(String)", password:"+password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("..., ");
  }
 
  Serial.println("Connected to the WiFi network");
 
}

void getWebResponse(char *url){
    HTTPClient http;

    Serial.println((String)"setting up ip info request: http.begin:"+url);
    http.begin(url);
    Serial.println("http.GET()...");
    int httpCode = http.GET();  //Make the request
    Serial.println("GET request sent to ipinfo");
 
    if (httpCode > 0) { //Check for the returning code 
        String payload = http.getString();
        Serial.println((String)"httpCode: "+httpCode);
        Serial.println((String)"payload: "+payload);
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
}
 
void loop() {
  // put your main code here, to run repeatedly:
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
   
      getWebResponse("http://jsonplaceholder.typicode.com/users/1");
      getWebResponse("http://checkip.dyndns.com");
      getWebResponse("http://bot.whatismyipaddress.com");
      //getWebResponse(endpoint + key);
  }
  delay(30000);
}
