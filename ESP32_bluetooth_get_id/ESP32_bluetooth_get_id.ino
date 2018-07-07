/*
 * based on https://techtutorialsx.com/2018/03/09/esp32-arduino-getting-the-bluetooth-device-address/
 * example output : 30:AE:A4:21:D2:AA
 * OUI Prefix     Company
 * 30:AE:A4       Espressif Inc.
 */

#include "esp_bt_main.h"
#include "esp_gap_bt_api.h"
#include "esp_bt_device.h"
 
bool initBluetooth(const char *deviceName)
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
  esp_bt_dev_set_device_name(deviceName); 
  esp_bt_gap_set_scan_mode(ESP_BT_SCAN_MODE_CONNECTABLE_DISCOVERABLE);
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
  if(!initBluetooth("ESP32 BT")){
      Serial.println("Bluetooth init failed");
  };
  printDeviceAddress();
  Serial.println("ESP32_bluetooth_get_id setup:end");
}
 
void loop() {
  
  }
