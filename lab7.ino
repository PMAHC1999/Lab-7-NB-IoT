#include <DHT.h>
#include "Magellan_BC95.h"
#define DHTTYPE DHT22
#define DHTPIN 7 // ต่อเข้าขา 7
//Token Key you can get from magellan platform
Magellan_BC95 magel; 
char auth[] = "bbfd9f42-608a-4de1-adad-ccb7c0ce4124"; // น ารหัสมาใส่บริเวณนี้
String payload;
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  //init Magellan LIB
  magel.begin();
  // init dht
  dht.begin();
}

void loop() {
    delay(2000);
    // get dht22 data
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    // convert to string
    String Temperature=String(t);
    String Humidity=String(h);
    payload="{\"Temperature\":"+Temperature+",\"Humidity\":"+Humidity+"}";
    magel.report(payload);
}
