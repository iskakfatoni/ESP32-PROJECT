/***************************************
 * Project 4 : KONTROL LED VIA BLYNK (NEW BLYNK 2.0)
 * Board  : ESP32 DEVKITC V4
 * Input  : 
 * Output : LED/RELAY
 * ESP32 Starter IoT 
 * www.ardutech.com
 ****************************************/
 //---GANTI SESUAI DENGAN TEMPLATE ID
 //---GANTI DEVICE NAME
 //---GANTI TOKEN BLYNK ANDA
#define BLYNK_TEMPLATE_ID "TMPLNh_9vgtG"
#define BLYNK_DEVICE_NAME "Kontrol Lampu"
#define BLYNK_AUTH_TOKEN "XlfIxLdAgXyEz6cqgSsi0Z0P0aUd1KyU"

#define BLYNK_PRINT Serial 
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;
// Sesuaikan dengan ssid dan password hotspot anda
char ssid[] = "iskak";
char pass[] = "89898989";
#define L1 15
#define L2 2
#define L3 0
#define L4 4
//========
BLYNK_WRITE(V0)
{ 
  int value1 = param.asInt();
  digitalWrite(L1,value1);  
}
//========
BLYNK_WRITE(V1)
{ 
  int value2 = param.asInt();
  digitalWrite(L2,value2);  
}
//========
BLYNK_WRITE(V2)
{ 
  int value3 = param.asInt();
  digitalWrite(L3,value3);  
}
//========
BLYNK_WRITE(V3)
{ 
  int value4 = param.asInt();
  digitalWrite(L4,value4);  
}
//====================
void setup(){
  Serial.begin(115200);
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(L3,OUTPUT);
  pinMode(L4,OUTPUT);   
  delay(200);
  Blynk.begin(auth, ssid, pass);  
}
//=======================
void loop(){
  Blynk.run();  
}
