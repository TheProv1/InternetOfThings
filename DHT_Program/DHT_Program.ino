#include <DHT.h>
DHT dht(D1, DHT22); //InputPin, Sensor(Un this case we are using DHT22 big white box, DHT11 will be a small blue box)

float hum, temp_f, temp_c;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() { //Core-code / Actionable Code
  // put your main code here, to run repeatedly:
  hum = dht.readHumidity();
  temp_f = dht.readTemperature(true); //When set to True --> Reads Farenhiet
  temp_c = dht.readTemperature(); // When set to False --> Reads Celcius

  Serial.print("Humidity: "); Serial.print(hum); Serial.print(", ");
  Serial.print("Temperature: "); Serial.print(temp_f); Serial.print(" F, ");
  Serial.print("Temperature: "); Serial.print(temp_c); Serial.println(" DegC");
  delay(5000);
}
