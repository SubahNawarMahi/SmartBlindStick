const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
 const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
 const int Buzzer =5; //hole
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600); // Starting Serial Terminal

}

void loop() {
  // put your main code here, to run repeatedly:
   long duration,sd, inches, cm;
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
     delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
     delayMicroseconds(10);
     digitalWrite(pingPin, LOW);
    pinMode(echoPin, INPUT);
     duration = pulseIn(echoPin, HIGH);
      sd=duration*0.034/2;   //if sd>2 && sd<10   then hole detected  sd >2 dilei hobe
      Serial.print(sd);
      Serial.println();
      if(sd>15)     //sd>2 chilo  15 kore disi
      {
        digitalWrite(Buzzer, HIGH);
      tone(Buzzer,700);
      }
      else
      {
        digitalWrite(Buzzer, LOW);
        noTone(Buzzer);
      }
      
    delay(100);
    

}
