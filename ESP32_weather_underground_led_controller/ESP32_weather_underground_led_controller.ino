#include <WiFi.h>
#include <HTTPClient.h>

//import sensitive data from external file, set gitignore to exclude the external file
#include "settings.h" 
const char* ssid = MY_WIFI_SSID;
const char* password =  MY_WIFI_PASSWORD;
const char* ipinfoiokey =  MY_IPINFOIO_API_KEY;

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
      getWebResponse("http://ipinfo.io?token=$951aec688e23e2");
      //getWebResponse(endpoint + key);
      //http://api.ipstack.com/134.201.250.155?access_key=YOUR_ACCESS_KEY
      getWebResponse("http://api.ipstack.com/134.201.250.155?access_key=a610c3d5565f86104557ad0b699d4593");
  }
  delay(30000);
}
