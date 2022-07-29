int light;
void setup() {
  
  pinMode(8,OUTPUT);
  Serial.begin(9600);
}

void loop() {

  light = analogRead(A0);

  if(light<20)
  {
    digitalWrite(8,HIGH);
    delay(1000);
    digitalWrite(8,LOW);
  }
  
  Serial.println(light);
  delay(1000);
  

}
