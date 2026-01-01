#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ThingSpeak.h>

DHT dht(D7, DHT22); //DHT
float tempc, tempf, hum;

char* ssid = "BITS-IOT";
char* password = "b!t$%2o25&pw";
HTTPClient httpclient;
WiFiClient client;

void setup() {
  dht.begin();
  pinMode(D6, INPUT); //IR Sensor
  pinMode(D5, INPUT); //Flame
  pinMode(A0, INPUT); //Gas Sensor

  Serial.begin(9600);
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  Serial.println("Wifi Connected");

}

int count_IR = 0, count_FLAME = 0;
float gas_reading;

void loop() {
  gas_reading = (analogRead(A0) / 1023.0);
  Serial.println(gas_reading);

  int flame_data = digitalRead(D5);

   String ir_text;
   String flame_text;

  if (flame_data == 0){
    count_FLAME++;
    Serial.print("Flame Sensor "); Serial.print(count_FLAME); Serial.println("times "); 
    flame_text = "Fire_detected";
  }

  else {
    Serial.println("No flame detected");
    flame_text = "No_Fire";
  }

   int ir_data = digitalRead(D6);

   if (ir_data == 0){
     count_IR++;
     Serial.print("IR Sensor "); Serial.print(count_IR); Serial.println("times "); 
     ir_text = "Motion";
   }

  else {// (data == 1){
    Serial.println("No IR Input");
    ir_text = "No_Motion";
   }

   tempc = dht.readTemperature();
   tempf = dht.readTemperature(true);
   hum = dht.readHumidity();

   Serial.print("TempC: "); Serial.print(tempc);
   Serial.print(" Tempf: "); Serial.print(tempf);
   Serial.print(" Hum: "); Serial.println(hum);
   
 

  String api = "http://10.30.97.73/insert.php?tc="+String(tempc)+"&h="+String(hum)+"&tf="+String(tempf)+"&f="+String(flame_text)+"&i="+String(ir_text)+"&g="+String(gas_reading);

  httpclient.begin(client, api);
  int code = httpclient.GET();

  Serial.print("Status Code:"); Serial.println(code);
  if (code > 0){
    Serial.println(httpclient.getString());
  }
  else{
    Serial.println(httpclient.errorToString(code));
  }

  httpclient.end();
  delay(5000);
}
