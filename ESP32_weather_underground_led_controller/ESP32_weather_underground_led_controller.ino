#include <WiFi.h>
#include <HTTPClient.h>
#include <algorithm>


//import sensitive data from external file, set gitignore to exclude the external file
#include "settings.h" 
const char* ssid = MY_WIFI_SSID;
const char* password =  MY_WIFI_PASSWORD;
const char* ipinfoiokey =  MY_IPINFO_API_KEY;
char* openweathermap_endpoint = MY_OPENWEATHERMAP_ENDPOINT;
 
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

char * getWebResponse(char *url){
    HTTPClient http;

    Serial.println((String)"setting up ip info request: http.begin:"+url);
    http.begin(url);
    Serial.println("http.GET()...");
    int httpCode = http.GET();  //Make the request
    Serial.println("GET request sent to ipinfo");
    char * buf = (char *) malloc (666); 
    if (httpCode > 0) { //Check for the returning code 
        String payload = http.getString();
        Serial.println((String)"httpCode: "+httpCode);
        Serial.println((String)"payload: "+payload);
        strcpy(buf, payload.c_str());
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
    http.end(); //Free the resources
    return buf;
}


void loop() {
  // put your main code here, to run repeatedly:
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
   
      getWebResponse("http://jsonplaceholder.typicode.com/users/1");
      String p = (String)getWebResponse("http://checkip.dyndns.com");//returns ip, need to parse response
      //<html><head><title>Current IP Check</title></head><body>Current IP Address: 218.214.207.194</body></html>
      Serial.print("p:");
      Serial.println(p);
      Serial.println(p.indexOf('Current IP Address: '));
      Serial.println(p);
      Serial.println(p.indexOf('</body></html>'));
      Serial.println(p);
      Serial.println(p.indexOf('</body>'));
      Serial.println(p);
      Serial.println(p.substring(76,91));
      Serial.println("--------------------------");
      char myip[16];
      //String myip = p.substring(76,91);
      p.substring(76,91).toCharArray(myip, 16);
      Serial.print("myip:");
      Serial.println(myip);
      
      //free (p);
      
      getWebResponse(openweathermap_endpoint);
      Serial.println("--------------------------");
      //http://api.ipstack.com/134.201.250.155?access_key=YOUR_ACCESS_KEY
      getWebResponse("http://api.ipstack.com/218.214.207.194?access_key=a610c3d5565f86104557ad0b699d4593");
      Serial.println("--------------------------");
      char url1[] = "http://api.ipstack.com/";
      char url3[] = "?access_key=a610c3d5565f86104557ad0b699d4593";
      Serial.println(sizeof(url1));//24
      Serial.println(sizeof(myip));//16
      Serial.println(sizeof(url3));//45
      char bigurl[40];
      bigurl[0] = 0;
      strcat(bigurl, url1);
      strcat(bigurl, myip);
      strcat(bigurl, url3);
      Serial.print("bigurl:");
      Serial.println(bigurl);
      getWebResponse(bigurl);
  }
  delay(120000);
}

