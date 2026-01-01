void setup() {
  // put your setup code here, to run once:
  //pinMode(D4, OUTPUT);
  pinMode(D1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(D4, HIGH);
  digitalWrite(D1, LOW);
  delay(50);
  //digitalWrite(D4, LOW);
  digitalWrite(D1, HIGH);
  delay(50);
}
