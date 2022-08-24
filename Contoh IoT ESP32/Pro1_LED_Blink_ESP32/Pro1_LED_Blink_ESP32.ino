/***************************************
 * Project 1 : LED BLINK
 * Board  : ESP32 DEVKITC V4
 * Input  : 
 * Output : 
 * ESP32 Starter IoT 
 * www.ardutech.com
 ****************************************/
 

void setup()
{
  pinMode(15,OUTPUT); 
}
void loop() {
  digitalWrite(15,HIGH); 
  delay(1000);
  digitalWrite(15,LOW);
  delay(1000); 
}
