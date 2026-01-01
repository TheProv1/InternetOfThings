void setup() {
  // put your setup code here, to run once:
  pinMode(D0, INPUT);
  pinMode(D4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = digitalRead(D0);
  if (data == 0){
    digitalWrite(D4, HIGH);
    Serial.print("Fire Detected \n");
  }

  else{
    digitalWrite(D4, LOW);
  }
  delay(10);
}
