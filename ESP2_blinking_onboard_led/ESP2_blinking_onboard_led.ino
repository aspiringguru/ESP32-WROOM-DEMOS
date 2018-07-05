/*
  ESP 32 Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  The ESP32 has an internal blue LED at D2 (GPIO 02)
  nb: external led connected to pin D2 (GPIO 02) is also be activated when internal blue led @ D2.
  nbb: led longer leg is positive (anode), shorter leg is negative (cathode)

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

int LED_BUILTIN = 2;//D2
int LED_PIN = 4;    //D4
int LED_PIN12 = 12;    //D4
int LED_PIN13 = 13;    //D4
int LED_PIN14 = 14;    //D4
int LED_PIN27 = 27;    //D4
int LED_PIN32 = 32;    //D4
int LED_PIN33 = 33;    //D4

int pinList[] = {27, 32, 33};

//int pinCount = 3;//see below to calc length of array.
// Calculate the size of the array
int pinCount = sizeof(pinList)/sizeof(int);
int timer = 200;

void setup() 
{
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 led blink");
  for(int i = 0; i < pinCount ; ++i) {
    Serial.println(i+(String)" value = "+pinList[i]);
    setupPin(pinList[i]);
  } 
    
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite (LED_PIN, LOW);
  pinMode(LED_PIN12, OUTPUT);
  digitalWrite (LED_PIN12, LOW);
  pinMode(LED_PIN13, OUTPUT);
  digitalWrite (LED_PIN13, LOW);
  setupPin(LED_PIN14);
}

void setupPin(int pinNumber){
  Serial.println((String)"setting up pin"+pinNumber);
  pinMode(pinNumber, OUTPUT);
  digitalWrite (pinNumber, LOW);
}

void loop() 
{
  Serial.println("blink HIGH");
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_PIN12, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_PIN13, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_PIN14, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  Serial.println("blink LOW");
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(LED_PIN, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_PIN12, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_PIN13, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_PIN14, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  for (int thisPin=0; thisPin<pinCount; thisPin++){
    //turn pin on
    Serial.println((String)"changing pin to HIGH then LOW : "+thisPin);
    digitalWrite(pinList[thisPin], HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(pinList[thisPin], LOW);
  }
}
