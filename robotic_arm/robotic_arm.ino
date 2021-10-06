/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo1;  // create servo object to control a servo 
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;// twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo1.attach(3);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(5);  // attaches the servo on pin 9 to the servo object 
  myservo3.attach(6);  // attaches the servo on pin 9 to the servo object 
  myservo4.attach(9);  // attaches the servo on pin 9 to the servo object 
  myservo5.attach(10);  // attaches the servo on pin 9 to the servo object 
  myservo5.write(20);

} 
 
void loop() 
{ 
  //PICK
  myservo3.write(160);
  myservo4.write(10);

  delay(100);  
  for(pos = 100; pos <= 170; pos += 1) // goes from 0 degrees to 180 degrees 
   {                                  // in steps of 1 degree 
    myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  delay(100);
  
   for(pos = 20; pos<=90; pos+=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo5.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  delay(100);
   for(pos = 150; pos<=175; pos+=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  delay(5000);
   for(pos = 90; pos>=50; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo5.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  delay(100);
  
  for(pos = 175; pos >= 150; pos -= 1) // goes from 0 degrees to 180 degrees 
   {                                  // in steps of 1 degree 
    myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }

  for(pos = 170; pos >= 20; pos -= 1) // goes from 0 degrees to 180 degrees 
   {                                  // in steps of 1 degree 
    myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  delay(100);
   for(pos = 150; pos<=175; pos+=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  delay(100);
   for(pos = 50; pos<=90; pos+=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo5.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  delay(2000);
   for(pos = 175; pos>=150; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  delay(100);
  for(pos = 20; pos <= 100; pos += 1) // goes from 0 degrees to 180 degrees 
   {                                  // in steps of 1 degree 
    myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
   for(pos = 90; pos>=20; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo5.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  delay(5000);
  
/*  for(pos = 40; pos>=10; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo4.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }

    for(pos = 90; pos <= 160; pos += 1) // goes from 0 degrees to 180 degrees 
   {                                  // in steps of 1 degree 
    myservo3.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }

  */
  
  
  
/*  for(pos = 160; pos>=90; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo3.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
    for(pos = 10; pos <= 40; pos += 1) // goes from 0 degrees to 180 degrees 
   {                                  // in steps of 1 degree 
    myservo4.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  */
} 
