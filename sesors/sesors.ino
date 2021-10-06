
#include <Servo.h> 


Servo myservo;

const int conveyor =  7;      // the number of the LED pin
const int actuator1 = 5;
const int actuator2 = 6;

const int servobutton = 3;
const int camera1 = 2;

int pos = 20;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  myservo.attach(9);
  
  pinMode(servobutton , INPUT_PULLUP);
  pinMode(camera1 , INPUT);
  
  pinMode(13, OUTPUT);
  pinMode(conveyor,OUTPUT);
  pinMode(actuator1,OUTPUT);
  pinMode(actuator2,OUTPUT);
  myservo.write(pos);
}

  int sensorValue1 = 0;
  int sensorValue2 = 0;
  int sensorValue3 = 0;
  int sensorValue4 = 0;
  
  int buttonstate = 0;
  int button_press = 0;
  int button_not_press = 0;
  
  int camera1state = 0;
  int camera1_true = 0;
  int camera1_false = 0;
  
  int constant = 180;
  char val = 0;
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
   if( Serial.available() ) 
   {
    val = Serial.read();      // read the serial port 
      if( val == 'Q' ) 
      {        // if it's an 'H', blink the light
      digitalWrite(conveyor, HIGH);
      }
      else if( val == 'A' ) 
      {        // if it's an 'H', blink the light
      digitalWrite(conveyor, LOW);
      }  
   }
  sensorValue1 = analogRead(A0);
  sensorValue2 = analogRead(A1);
  sensorValue3 = analogRead(A2);
  sensorValue4 = analogRead(A3);
  
  // print out the value you read:
/*  Serial.print(sensorValue1);
  Serial.print("--");
  
  Serial.print(sensorValue2);
  Serial.print("--");
  
  Serial.print(sensorValue3);
  Serial.print("--");

  Serial.println(sensorValue4);
*/
  if(sensorValue1 <= constant)
  {
   //ACTUATOR SENSOR
    Serial.println("actuator\n");
    if ( button_press == 1)
    {
      Serial.println("reject\n");
      //Serial.println("because bottle is not sealed");
    digitalWrite(conveyor , LOW);
    
    digitalWrite(actuator1, HIGH);
    digitalWrite(actuator2, LOW);
    delay(4000);
    Serial.println("unseal\n");
    digitalWrite(actuator1, LOW);
    digitalWrite(actuator2, HIGH);
    button_press = 0;
    
    delay(4000);
    digitalWrite(actuator1, LOW);
    digitalWrite(actuator2, LOW);
    digitalWrite(conveyor , HIGH);
    delay(800);
    Serial.println("actuator_clear\n");
    }  
  
    else if ( camera1_false == 1)
    {
      Serial.println("reject\n");
      //Serial.println("because no cap detected");
    digitalWrite(conveyor , LOW);
    
    digitalWrite(actuator1, HIGH);
    digitalWrite(actuator2, LOW);
    delay(4000);
    Serial.println("uncap\n");
    camera1_false = 0;
    
    digitalWrite(actuator1, LOW);
    digitalWrite(actuator2, HIGH);

    delay(4000);
    digitalWrite(actuator1, LOW);
    digitalWrite(actuator2, LOW);
    digitalWrite(conveyor , HIGH);
    delay(800);
    Serial.println("actuator_clear\n");
    } 
   else
  {
    Serial.println("accept\n");
  delay(1000);
  } 

  }

  if(sensorValue2 <= constant)
  {
   //SERVO SENSOR
   Serial.println("servo\n");
  digitalWrite(conveyor , LOW);
  for(pos = 20; pos <= 130; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    buttonstate = digitalRead(servobutton);
      
      if (buttonstate == HIGH) {
    digitalWrite(13, LOW);
    button_not_press = 1;
  } 
  else {
    digitalWrite(13, HIGH);
    button_press = 1;
  }
    delay(25);                       // waits 15ms for the servo to reach the position 
  }
    
    for(pos = 130; pos>=20; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(8);                       // waits 15ms for the servo to reach the position 
  }
  
  digitalWrite(conveyor , HIGH);
  delay(800);
  Serial.println("servo_clear\n");
  }
  
  if(sensorValue3 <= constant)
  {
    //CAMERA HEIGHT SENSOR
  Serial.println("cam2\n");
  digitalWrite(conveyor , LOW);
  delay(2000);
  digitalWrite(conveyor , HIGH);
  delay(700);
  Serial.println("cam2_clear\n");
  }
  
   if(sensorValue4 <= constant)
  {
    Serial.println("cam1\n");
    //CAMERA COLOUR SENSOR
  digitalWrite(conveyor , LOW);
  delay(1000);
  camera1state = digitalRead(camera1);
  if (camera1state == HIGH)
  {
   // Serial.println("CAP IS FINE");
  camera1_true = 1;
  digitalWrite(13, HIGH);
  }
  else
  {
    //Serial.println("CAP ERROR");
  camera1_false = 1;
  digitalWrite(13, LOW);
  }
  delay(1000);
  digitalWrite(conveyor , HIGH);
  
  delay(700);
  Serial.println("cam1_clear\n");
  }
  digitalWrite(actuator1, LOW);
  digitalWrite(actuator2, LOW);
  
}
