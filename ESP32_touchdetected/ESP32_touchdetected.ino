/*
This is un example howto use Touch Intrrerupts
The bigger the threshold, the more sensible is the touch
*/

int threshold = 40;
bool touch0detected = false;
bool touch3detected = false;

void gotTouch0(){
 touch0detected = true;
}

void gotTouch3(){
 touch3detected = true;
}

void setup() {
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Interrupt Test");
  touchAttachInterrupt(T0, gotTouch0, threshold);
  touchAttachInterrupt(T3, gotTouch3, threshold);
}

void loop(){
  //todo: implement elseif, look at dynamic addressing?
  if(touch0detected){
    touch0detected = false;
    Serial.println("Touch 0 detected");
  }
  if(touch3detected){
    touch3detected = false;
    Serial.println("Touch 3 detected");
  }
  if (!touch0detected && !touch3detected){
    Serial.println("Touch 0 && Touch 3 not detected");
  }
  delay(500);
}
