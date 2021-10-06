/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
const int Sensor1 = 2;
const int Sensor2 = 3;
const int Sensor3 = 4;
const int Sensor4 = 5;// the number of the pushbutton pin
const int conveyor =  12;      // the number of the LED pin
const int buttonPin = 10;// the number of the pushbutton pin

// variables will change:
int Sensor1State = 0;         // variable for reading the pushbutton status
int Sensor2State = 0;
int Sensor3State = 0;
int Sensor4State = 0;
int buttonState = 0;
int bottleState = 0; 

void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
    pinMode(conveyor, OUTPUT);      
    pinMode(Sensor1, INPUT);
    pinMode(Sensor2, INPUT);
    pinMode(Sensor3, INPUT);
    pinMode(Sensor4, INPUT);
    digitalWrite(conveyor, LOW);  
} 
 
void loop() 
{ 
/*  for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(20);                       // waits 15ms for the servo to reach the position 
    buttonState = digitalRead(buttonPin);
  }
*/  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
    digitalWrite(conveyor, LOW);    

  if (digitalRead(Sensor1) == LOW) {         
    digitalWrite(conveyor, HIGH);
    delay(3000);
    digitalWrite(conveyor, LOW);
    delay(1000);    
  }
/*  if (digitalRead(Sensor2) == HIGH) {
    // turn LED off:
    digitalWrite(conveyor, HIGH);
    delay(3000);
    digitalWrite(conveyor, LOW);    
  }
  if (digitalRead(Sensor3) == HIGH) {
    // turn LED off:
    digitalWrite(conveyor, HIGH);
    for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(30);                       // waits 15ms for the servo to reach the position 
    buttonState = digitalRead(buttonPin);
      
  if (buttonState == HIGH) {
    // turn LED off:
     
  }
  }
      digitalWrite(conveyor, LOW);
  }
      for(pos = 180; pos >= 0; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);
  }
  if (digitalRead(Sensor4) == HIGH) {
    // turn LED off:
    digitalWrite(conveyor, HIGH);
    delay(5000);
    digitalWrite(conveyor, LOW);    
  }
 
/*  for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
 */ 
// delay(5000); 
} 
