//gsm
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);//ST, SR
char msg;
char call;

const int s=4;
//gsm

int light;
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
 const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
 const int Buzzer =5; //hole
void setup() {

 //gsm
  pinMode(s,INPUT_PULLUP);
  mySerial.begin(9600);
  Serial.println("GSM SIM900A BEGIN");
  Serial.println("Enter character for control option:");
  Serial.println("h : to disconnect a call");
  Serial.println("i : to receive a call");
  Serial.println("s : to send message");
  Serial.println("c : to make a call");  
  Serial.println("e : to redial");
  Serial.println();
  delay(100);
  //gsm
  pinMode(8,OUTPUT); 
  Serial.begin(9600);
}

bool b;


void loop() {

 
//  
// if (mySerial.available()>0)
// Serial.write(mySerial.read());

  light = analogRead(A0);

 //gsm
 
  
  if(light<20)
  {
    digitalWrite(8,HIGH);
    delay(1000);
    digitalWrite(8,LOW);
  }
  
  Serial.println(light);
  delay(1000);

  //last sonar
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
      Serial.println("hole distance:");
      if(sd>10)     //sd>2 chilo  15 kore disi
      {
       digitalWrite(Buzzer, HIGH);
      tone(Buzzer,2000);
      }
      else
      {
        digitalWrite(Buzzer, LOW);
        noTone(Buzzer);
      }

b = digitalRead(s);
  if(b==LOW)
  {
      
  }
  if ( b==LOW)
  {
    SendMessage();
    Serial.println("sending message");
    delay(60000);
  }
}
void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+8801825556567\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Help I'm in danger!!!");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

void ReceiveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
  delay(1000);
  if (mySerial.available()>0)
  {
    msg=mySerial.read();
    Serial.print(msg);
  }
}

void MakeCall()
{
  mySerial.println("ATD+60XXXXXXXXX;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
  Serial.println("Calling  "); // print response over serial port
  delay(1000);
}


void HangupCall()
{
  mySerial.println("ATH");
  Serial.println("Hangup Call");
  delay(1000);
}

void ReceiveCall()
{
  mySerial.println("ATA");
  delay(1000);
  {
    call=mySerial.read();
    Serial.print(call);
  }
}

void RedialCall()
{
  mySerial.println("ATDL");
  Serial.println("Redialing");
  delay(1000);
}
