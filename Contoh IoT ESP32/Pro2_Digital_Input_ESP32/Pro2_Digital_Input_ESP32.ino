/***************************************
 * Project 2 : DIGITAL INPUT
 * Input  : Push On
 * Output : 
 * ESP32 Starter IoT 
 * www.ardutech.com
 ****************************************/
#define SW1 12
#define SW2 14

void setup() {  
  pinMode(SW1,INPUT_PULLUP);
  pinMode(SW2,INPUT_PULLUP);
  Serial.begin(115200);
  delay(200);
  Serial.println("Tekan SW1 dan SW2...");
}

void loop() { 
  if(digitalRead(SW1)==LOW){
    Serial.println("SW1 ON ...");  
    delay(200);
  }
  else if(digitalRead(SW2)==LOW){
    Serial.println("SW2 ON ..."); 
    delay(200); 
  }
}
