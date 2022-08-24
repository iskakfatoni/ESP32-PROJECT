/***************************************
 * Project 6 : MONITORING DHT11 VIA BLYNK (NEW BLYNK 2.0)
 * Board  : ESP32 DEVKITC V4
 * Input  : DHT11
 * Output : 
 * ESP32 Starter IoT 
 * www.ardutech.com
 ****************************************/
//---GANTI SESUAI DENGAN TEMPLATE ID
 //---GANTI DEVICE NAME
 //---GANTI TOKEN BLYNK ANDA
#define BLYNK_TEMPLATE_ID "TMPLTf4yGvIp"
#define BLYNK_DEVICE_NAME "MONITORING DHT11"
#define BLYNK_AUTH_TOKEN "LhNNK7BC_5yurnNEuO8TSkYMfv_v7SJ7"
#define BLYNK_PRINT Serial 
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;
// Sesuaikan dengan ssid dan password hotspot anda
char ssid[] = "iskak";
char pass[] = "89898989";

#include "DHT.h"
#define DHTPIN 18   
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
int humi, temp; 
//==============================
void setup(){  
  Serial.begin(115200);   
  delay(10);
  Blynk.begin(auth, ssid, pass);     
  dht.begin();  
}
//================================
void sendData(){     
  humi = dht.readHumidity();
  temp = dht.readTemperature();
   if (isnan(humi) || isnan(temp)) {
    Serial.println("DHT11 tidak terbaca... !");
    return;
  }
  else{   
   Blynk.virtualWrite(V0, temp); 
   Blynk.virtualWrite(V1, humi); 
   Serial.println(temp);
   Serial.println(humi);
   Serial.println();
  }
}
//======================
void loop(){
  Blynk.run();
  delay(1000);
  sendData();
}
