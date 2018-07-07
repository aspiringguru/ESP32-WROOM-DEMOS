/*
 * based on https://techtutorialsx.com/2018/03/09/esp32-arduino-getting-the-bluetooth-device-address/
 * example output : 30:AE:A4:21:D2:AA
 */

#include "esp_bt_main.h"
#include "esp_bt_device.h"
 
bool initBluetooth()
{
  Serial.println("initBluetooth():start");
  if (!btStart()) {
    Serial.println("Failed to initialize controller");
    return false;
  }
 
  if (esp_bluedroid_init() != ESP_OK) {
    Serial.println("Failed to initialize bluedroid");
    return false;
  }
 
  if (esp_bluedroid_enable() != ESP_OK) {
    Serial.println("Failed to enable bluedroid");
    return false;
  }
  Serial.println("initBluetooth():end");
}
 
void printDeviceAddress() {
 
  const uint8_t* point = esp_bt_dev_get_address();
 
  for (int i = 0; i < 6; i++) {
 
    char str[3];
 
    sprintf(str, "%02X", (int)point[i]);
    Serial.print(str);
 
    if (i < 5){
      Serial.print(":");
    }
 
  }
  Serial.println("");
}
 
void setup() {
  Serial.begin(115200);
  Serial.println("ESP32_bluetooth_get_id setup:start");
  initBluetooth();
  printDeviceAddress();
  Serial.println("ESP32_bluetooth_get_id setup:end");
}
 
void loop() {}
