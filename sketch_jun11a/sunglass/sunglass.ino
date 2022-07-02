#define trigPin 13

#define echoPin 12

#define buzzer 6

void setup()
{
pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

pinMode(buzzer,OUTPUT);

}

void loop()

{

long duration, distance;

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = (duration/2) / 29.1;

if (distance < 45)     // This is where checking the distance you can change the value

{

digitalWrite(buzzer,HIGH);

} else

{

digitalWrite(buzzer,LOW);

} delay(500);

}
