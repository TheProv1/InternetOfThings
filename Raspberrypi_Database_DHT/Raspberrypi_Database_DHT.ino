#include<DHT.h>
#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>
#include<ThingSpeak.h>
DHT dht(D5,DHT22);
float hum,temp_c,temp_f;
char* ssid = "BITS-IOT";
char* pass = "b!t$%2o25&pw";
WiFiClient wifiClient;

void setup() {
Serial.begin(9600);
dht.begin();
Serial.println("Connecting to WiFi..");
WiFi.begin(ssid,pass);
while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
    }
Serial.println("WiFi Connected");
}

void loop() {
  hum = dht.readHumidity();
  temp_c = dht.readTemperature();
  temp_f = dht.readTemperature(true);

  // Simulate values if sensor fails
  if (isnan(hum) || isnan(temp_c) || isnan(temp_f)) {
    hum = 0.0;
    temp_c = 0.0;
    temp_f = 0.0;
  }

  Serial.printf("Humidity: %.2f, Temperature: %.2f*C, %.2f*F\n", hum, temp_c, temp_f);

  HTTPClient client;
  String api = "http://10.30.97.73/insert.php?h=" + String(hum) + "&t=" + String(temp_c) + "&f=" + String(temp_f);
  
  client.begin(wifiClient, api);
  int code = client.GET();

  Serial.print("Status Code: "); Serial.println(code);
  if (code > 0) {
    Serial.println(client.getString());
  } else {
    Serial.println(client.errorToString(code));
  }

  client.end();
  delay(5000);
}
