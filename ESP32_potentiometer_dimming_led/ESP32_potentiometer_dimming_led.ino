/****************************************************** 
* ESP32 Analog Input Test 
* Analog Input: ADC_1_0 pin ==> GPIO36 (VP).
* 
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

*****************************************************/
//Analog Input
#define ANALOG_PIN_0 13  //D13 
int analog_value = 0;

// PMW LED
#define LED_PIN 2 //onboard led & D2
int freq = 5000;
int ledChannel = 0;
int resolution = 8;
int dutyCycle = 0;

void setup()
{
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Analog IN/OUT Test");
   ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_PIN, ledChannel);
  ledcWrite(ledChannel, dutyCycle);
}

void loop()
{
  analog_value = analogRead(ANALOG_PIN_0);
  Serial.println(analog_value);
  dutyCycle = map(analog_value, 0, 4095, 0, 255);
  ledcWrite(ledChannel, dutyCycle);
  delay(500);
}


