// ESP32 Touch Test
// Just test touch pin - Touch0 is T0 which is on GPIO 4.

void setup()
{
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Test");
}

void loop()
{
  Serial.println((String)"touchRead(T0) : "+touchRead(T0));  //D4 = works
  Serial.println((String)"touchRead(T2) : "+touchRead(T2));  //no response from D2
  Serial.println((String)"touchRead(T3) : "+touchRead(T3));  //D15 = works
  Serial.println((String)"touchRead(T4) : "+touchRead(T4));  //D13 = works
  Serial.println((String)"touchRead(T5) : "+touchRead(T5));  //D12 = works
  Serial.println((String)"touchRead(T6) : "+touchRead(T6));  //D14 = works
  Serial.println((String)"touchRead(T7) : "+touchRead(T7));  //D27 = works
  Serial.println((String)"touchRead(T8) : "+touchRead(T8));  //D32 = works
  Serial.println((String)"touchRead(T9) : "+touchRead(T9));  //D33 = works
  Serial.println("--------------------------------");
  delay(1000);
}
