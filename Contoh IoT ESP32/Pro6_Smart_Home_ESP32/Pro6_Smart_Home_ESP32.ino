/***************************************
 * Project 6 : SMART HOME VIA BLYNK (NEW BLYNK 2.0)
 * Board  : ESP32 DEVKITC V4
 * Input  : MQ2, DHT11, SWITCH
 * Output : LED/RELAY,NOTIFIKASI, BUZZER
 * ESP32 Starter IoT 
 * www.ardutech.com
 ****************************************/
 //---GANTI SESUAI DENGAN TEMPLATE ID
 //---GANTI DEVICE NAME
 //---GANTI TOKEN BLYNK ANDA
#define BLYNK_TEMPLATE_ID "TMPLEvfdWYnT"
#define BLYNK_DEVICE_NAME "SMART HOME"
#define BLYNK_AUTH_TOKEN "AurzN9f6zxU12MEBakg8Wm-ngBilxCSj"

#define BLYNK_PRINT Serial
//---GANTI SESUAI DENGAN JARINGAN WIFI
//---HOTSPOT ANDA
char ssid[] = "iskak";
char pass[] = "89898989";

#define MQ2_SENSOR  19
#define bell 13
#define L1 15
#define L2 2
#define L3 0
#define L4 4
#define SW 12

#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#define DHTPIN 18
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int MQ2_SENSOR_Value = 0;
char auth[] = BLYNK_AUTH_TOKEN;
boolean st,fg,fu;
int humi, temp; 
//==============================
void cek_DHT11(){
  humi = dht.readHumidity();  
  temp = dht.readTemperature();
  if (isnan(humi) || isnan(temp)) {
    Serial.println("DHT11 tidak terbaca... !");
    return;
  }
  else{   
    Serial.print("Temp=");
    Serial.println(temp);
    Serial.print("Humi=");
    Serial.println(humi);
    Blynk.virtualWrite(V0, temp);  
    Blynk.virtualWrite(V1, humi);  
  }  
}
//==============================
BLYNK_WRITE(V2)//Lampu 1
{ 
  int value1 = param.asInt();
  digitalWrite(L1,value1);  
}
//==============================
BLYNK_WRITE(V3)//Lampu 2
{ 
  int value2 = param.asInt();
  digitalWrite(L2,value2);  
}
//==============================
BLYNK_WRITE(V4)//Lampu 3
{ 
  int value3 = param.asInt();
  digitalWrite(L3,value3);  
}
//==============================
BLYNK_WRITE(V5)//Lampu 4
{ 
  int value5 = param.asInt();
  ledcWrite(0,value5);     
}
//==============================
BLYNK_WRITE(V6)//Bell
{ 
  int value6 = param.asInt();
  digitalWrite(bell,value6);  
}
//==============================
void cek_SW(){  
    if(digitalRead(SW)==LOW){
      Blynk.logEvent("awas", "Ada pencuri...");
      Serial.println("SW ON...");
      delay(500);
    }
}
//==============================
void cekSensorGas(){
   MQ2_SENSOR_Value = digitalRead(MQ2_SENSOR);
    if ((MQ2_SENSOR_Value==0)&&(fg==0)) 
       { 
         Serial.println("==>Gas terdeteksi");
         Blynk.logEvent("awas", "Gas bocor terdeteksi!");
         fg=1;         
         delay(1000);
        }
     else if((MQ2_SENSOR_Value==1)&&(fg==1)) 
       {                
        fg=0;
        delay(1000);
       }
 }
//==============================
void setup()
{
  Serial.begin(115200);  
  ledcSetup(0, 5000, 8);   
  ledcAttachPin(L4, 0);
  pinMode(SW,INPUT_PULLUP);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(bell, OUTPUT);
  pinMode(MQ2_SENSOR, INPUT);     
  Blynk.begin(auth, ssid, pass); 
  delay(100);
  dht.begin();  
}
//==============================
void loop()
{  
  cekSensorGas();
  cek_SW();
  cek_DHT11();
  Blynk.run(); 
}
