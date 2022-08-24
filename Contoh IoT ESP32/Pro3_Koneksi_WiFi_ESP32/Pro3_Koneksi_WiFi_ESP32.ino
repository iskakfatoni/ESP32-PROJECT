/***************************************
 * Project 3 : KONEKSI WiFi
 * Board  : ESP32 DEVKITC V4
 * Input  : 
 * Output : 
 * ESP32 Starter IoT 
 * www.ardutech.com
 ****************************************/
 
#include "WiFi.h"
// Ganti dengan jaringan WiFi anda
const char* ssid = "iskak";
const char* password = "89898989";
void setup() {  
  Serial.begin(115200);
  Serial.println("Tes koneksi WiFi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println("WiFi Connected");
  Serial.print("IP address:");
  Serial.println(WiFi.localIP());
}

void loop() {
  
}
