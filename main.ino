// Motor Pins
 // Left Motor
 const int in1 = 2; // left motor forward
 const int in2 = 3; // left motor reverse
 const int in3 = 4; // right motor reverse
 const int in4 = 5; // right motor forward
 const int enA = 7;
 const int enB = 6;


// IR Sensor pins
 const int s1 = 8;
 const int s2 = 9;
 const int s3 = 10;
 const int s4 = 11;




void setup() {
 // put your setup code here, to run once:


 // // IR Senors
 pinMode(s1, INPUT);
 pinMode(s2, INPUT);
 pinMode(s3, INPUT);
 pinMode(s4, INPUT);


 // Motor
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);


 Serial.begin(9600);


}


// move in which Directions


void goRight() {


 digitalWrite(in1, HIGH); // Forward
 digitalWrite(in2, LOW);   // Reverse
 analogWrite(enA, 180);


 digitalWrite(in3, HIGH);  // Reverse
 digitalWrite(in4, LOW); // Forward
 analogWrite(enB, 90);


}


void goLeft() {


 digitalWrite(in1, LOW); // Forward
 digitalWrite(in2, HIGH); // Reverse
 analogWrite(enA, 90);


 digitalWrite(in3, LOW); // Reverse
 digitalWrite(in4, HIGH); // Forward
 analogWrite(enB, 180);


}


void goForward() {


 digitalWrite(in1, HIGH); // Forward
 digitalWrite(in2, LOW); // Reverse
 analogWrite(enA, 180);


 digitalWrite(in3, LOW); // Reverse
 digitalWrite(in4, HIGH); // Forward
 analogWrite(enB, 180);


}


void goBackward() {


 digitalWrite(in1, LOW); // Forward
 digitalWrite(in2, HIGH); // Reverse
 analogWrite(enA, 180);


 digitalWrite(in3, HIGH); // Reverse
 digitalWrite(in4, LOW); // Forward
 analogWrite(enB, 180);
 
}


void stop() {


 digitalWrite(in1, LOW); // Forward
 digitalWrite(in2, LOW); // Reverse
 analogWrite(enA, 0);


 digitalWrite(in3, LOW); // Reverse
 digitalWrite(in4, LOW); // Forward
 analogWrite(enA, 0);


}




void loop() {
 // put your main code here, to run repeatedly:
 // Sensors
  // int v1 = digitalRead(s4); // Left
  // int v2 = digitalRead(s3); // Middle Left
  // int v3 = digitalRead(s2); // Middle Right
  // int v4 = digitalRead(s1); // Right 

 int v1 = digitalRead(s1); // Right
 int v2 = digitalRead(s2); // Middle Right
 int v3 = digitalRead(s3); // Middle Left
 int v4 = digitalRead(s4); // Left


  Serial.print(v1);
  Serial.print(" ");
  Serial.print(v2);
  Serial.print(" ");
  Serial.print(v3);
  Serial.print(" ");
  Serial.print(v4);
  Serial.println(" ");


  if (  ( (v1 == 1) && (v2 == 0) && (v3 == 0) && (v4 == 1) )
    ||  ( (v1 == 1) && (v2 == 1) && (v3 == 0) && (v4 == 1) )
    ||  ( (v1 == 1) && (v2 == 0) && (v3 == 1) && (v4 == 1) )
    ||  ( (v1 == 0) && (v2 == 0) && (v3 == 0) && (v4 == 0) )
  ) {
    goForward();
  }
  else if ( 
        ( (v1 == 1) && (v2 == 0) && (v3 == 0) && (v4 == 0) ) 
    ||  ( (v1 == 1) && (v2 == 1) && (v3 == 0) && (v4 == 0) ) 
    ||  ( (v1 == 1) && (v2 == 1) && (v3 == 1) && (v4 == 0) )
  ) {
    goLeft();
  }
  else if (
        ( (v1 == 0) && (v2 == 0) && (v3 == 0) && (v4 == 1) ) 
    ||  ( (v1 == 0) && (v2 == 0) && (v3 == 1) && (v4 == 1) ) 
    ||  ( (v1 == 0) && (v2 == 1) && (v3 == 1) && (v4 == 1) )

  ) {
    goRight();
  }
  else if ( 
        ( (v1 == 1) && (v2 == 1) && (v3 == 1) && (v4 == 1) )
    ||  ( (v1 == 0) && (v2 == 1) && (v3 == 1) && (v4 == 0) ) 
  ) { 
    goBackward();
  }
  else {
    stop();
  }

 delay(2.5);
}
