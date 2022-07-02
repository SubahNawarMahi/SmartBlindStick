const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
 const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
 
 const int pingPin2 = 12; // Trigger Pin of Ultrasonic Sensor
 const int echoPin2 = 10; // Echo Pin of Ultrasonic Sensor
 
 const int flamePin = 8;
 int Flame = HIGH;
 
 const int Buzzer1 =5;
 
 int In1 = 3;
 
 
 void setup() {
   pinMode(flamePin, INPUT);
    pinMode(A0,INPUT);
 
    pinMode(In1,OUTPUT);
    Serial.begin(9600); // Starting Serial Terminal
    
 }
 
 void loop() {
  /*long duration, inches, cm,sd;
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pingPin, LOW);
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    sd=duration*0.034/2;
    //inches = microsecondsToInches(duration);
    cm = microsecondsToCentimeters(duration);
    if(sd<= 15)
    {
     digitalWrite(Buzzer1, HIGH);
     tone(Buzzer1,5000);
    }
    else if (sd>15)
    {
     digitalWrite(Buzzer1, LOW);
     noTone(Buzzer1);
    }
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(100);*/
    
 
 
   
 
 
 
 
    /*Water Sensor Code Start*/
    int a = analogRead(A0);
 
    if(a>300)
    {
      digitalWrite(Buzzer1, HIGH);
      tone(Buzzer1,200);
 
    }
    else
    {
     digitalWrite(Buzzer1, LOW);
     noTone(Buzzer1); 
 
     
    }
     Serial.println(a);
    /*Water Sensor Code End*/
 
    /* flame code start*/
    Flame = digitalRead(flamePin);
 
  // Serial.println(Flame);
   
   if (Flame== LOW)
   {
      digitalWrite(Buzzer1, HIGH);
      tone(Buzzer1,100);
      //Serial.println("HELLO");
  
   }
   else
   {
     digitalWrite(Buzzer1, LOW);
     noTone(Buzzer1);
    // digitalWrite(3,LOW);
 
   
   } 
 
    /* flame code end*/
  
  /*Motor Driver Code Start*/
 
    if(Flame == LOW || a>300)
    {
     digitalWrite(In1,HIGH);
    }
    else
    {
     digitalWrite(In1,LOW);
     
    }
 
     /*Motor Driver Code End*/
 
    
    
 
    
 
 long duration,sd, inches, cm;
 long duration1, sd1,inches1, cm1;
 pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    pinMode(pingPin2, OUTPUT);
    digitalWrite(pingPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    digitalWrite(pingPin2, HIGH);
    delayMicroseconds(10);
     digitalWrite(pingPin, LOW);
    pinMode(echoPin, INPUT);
    duration1 = pulseIn(echoPin, HIGH);
    sd1=duration1*0.034/2;
   // inches1 = microsecondsToInches(duration1);
    cm1 = microsecondsToCentimeters(duration1);
   /* if(sd1<= 15)
    {
     digitalWrite(Buzzer1, HIGH);
     tone(Buzzer1,5000);
    }
    else if (sd1>15)
    {
     digitalWrite(Buzzer1, LOW);
     noTone(Buzzer1);
    }*/
   // Serial.print("sonar upper ");
   // Serial.print(inches1);
  //  Serial.print("in, ");
 //   Serial.print(cm1);
 //   Serial.print("cm");
 //   Serial.println();
    delay(100);
   digitalWrite(pingPin2, LOW);
    pinMode(echoPin2, INPUT);
    duration = pulseIn(echoPin2, HIGH);
    sd=duration*0.034/2;
  //  inches = microsecondsToInches(duration);
    cm = microsecondsToCentimeters(duration);
     if (sd > 15 && sd1 > 15)
     {
     digitalWrite(Buzzer1, LOW);
     noTone(Buzzer1);
      digitalWrite(In1,LOW);
    // Serial.println(sd1);
    }
    else if(sd <= 15 && sd1<=15)
    {
     digitalWrite(Buzzer1, HIGH);
     tone(Buzzer1,7000);
      digitalWrite(In1,HIGH);
     // Serial.println(sd1+ "later");
    }
    else if(sd<=15 && sd1>15)
    {
     digitalWrite(Buzzer1, HIGH);
     tone(Buzzer1,7000);
      digitalWrite(In1,HIGH);
     
     }
     else if(sd>15 && sd1<=15)
    {
     digitalWrite(Buzzer1, HIGH);
     tone(Buzzer1,2000);       
      digitalWrite(In1,HIGH);
     }
   
 //   Serial.print("sonar lower ");
 //   
 //   Serial.print(cm);
 //   Serial.print("cm");
 //   Serial.println();
    delay(100);
 
    
 }
 
 
 
 
 
 long microsecondsToInches(long microseconds) {
    return microseconds / 74 / 2;
 }
 
 long microsecondsToCentimeters(long microseconds) {
    return microseconds / 29 / 2;
 }
