/* FILE:    HCMODU0082_Serial_Dot_Matrix_Example
   DATE:    19/03/15
   VERSION: 0.1
   
REVISIONS:

19/03/15 Created version 0.1

This is an example of how to use the Hobby Components 8x8 serial dot matrix
module (HCOPTO0014). To use this example sketch you will need to download 
and install the HCMAX7921 library available from the software section of our
support forum (forum.hobbycomponents.com) or on github:
(https://github.com/HobbyComponents)

The library assumes you are using one module. If you have more than one module
connected together then you will need to change the following line in the 
libraries HCMAX7219.h header file to the number of drivers you have connected:

#define NUMBEROFDRIVERS 1 <- Change this number

PINOUT:

MODULE.....UNO/NANO.....MEGA
VCC........+5V..........+5V
GND........GND..........GND
DIN........11...........51
CS (LOAD)..10...........10
CLK........13...........52

You may copy, alter and reuse this code in any way you like, but please leave
reference to HobbyComponents.com in your comments if you redistribute this code.
This software may not be used directly for the purpose of promoting products that
directly compete with Hobby Components Ltd's own range of products.

THIS SOFTWARE IS PROVIDED "AS IS". HOBBY COMPONENTS MAKES NO WARRANTIES, 
WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ACCURACY OR
LACK OF NEGLIGENCE. HOBBY COMPONENTS SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE
FOR ANY DAMAGES INCLUDING, BUT NOT LIMITED TO, SPECIAL, INCIDENTAL OR 
CONSEQUENTIAL DAMAGES FOR ANY REASON WHATSOEVER. */

/* Include the HCMAX7219 and SPI library */
#include <HCMAX7219.h>
#include "SPI.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3f for a 16 chars and 2 line display

/* Set the LOAD (CS) digital pin number*/
#define LOAD 10

/* Create an instance of the library */
HCMAX7219 HCMAX7219(LOAD);


void setup() 
{    
    lcd.init();                      // initialize the lcd 
 
  // Print a message to the LCD.
    lcd.backlight();
     lcd.setCursor(0,0);
    lcd.print(">CONVEYOR BELT>");
      HCMAX7219.printMatrix("H", 40);
      HCMAX7219.printMatrix("E", 32);
      HCMAX7219.printMatrix("L", 24);
      HCMAX7219.printMatrix("L", 16);
      HCMAX7219.printMatrix("O", 8);      
      HCMAX7219.Refresh(); 
     delay(5000); 
}

int period = 30;
int i = 0;
/* Main program */
void loop() 
{
  byte Loopcounter;
  int Position;

  /* Clear the output buffer */
 
  HCMAX7219.Clear();
  
  /* SCROLL SOME TEXT 2 TIMES BEFORE MOVING ON */

    for(Position=0; Position <= 160; Position++)
    {
      HCMAX7219.printMatrix("PROJECT-NAME===", Position);
      HCMAX7219.Refresh();
      delay(period);
      i = Position/11;
        lcd.setCursor(i,1);
      lcd.print("->>>>");

    }
     for(Position=0; Position <= 472; Position++)
    {
      HCMAX7219.printMatrix("IMAGE PROCESSING BASED GLASS JAM CAP INSPECTION SYSTEM", Position);
      HCMAX7219.Refresh();
      delay(period);
      i = Position/30;
        lcd.setCursor(i,1);
      lcd.print("->>>>");

    }
     for(Position=0; Position <= 304; Position++)
    {
      HCMAX7219.printMatrix("BY FAHAD-UR-REHMAN & ABDUL-REHMAN", Position);
      HCMAX7219.Refresh();
      delay(period);
      i = Position/20;
        lcd.setCursor(i,1);
      lcd.print("->>>>");

    }
     for(Position=0; Position <= 232; Position++)
    {
      HCMAX7219.printMatrix("SUPERVISOR=NOAMAN MASOUD", Position);
      HCMAX7219.Refresh();
      delay(period);
            i = Position/15;
        lcd.setCursor(i,1);
      lcd.print("->>>>");
    }    
     for(Position=0; Position <= 144; Position++)
    {
      HCMAX7219.printMatrix("PROJECT-PARTS", Position);
      HCMAX7219.Refresh();
      delay(period);
            i = Position/10;
        lcd.setCursor(i,1);
      lcd.print("->>>>");

    }
     for(Position=0; Position <= 160; Position++)
    {
      HCMAX7219.printMatrix("1.CONVEYOR-BELT", Position);
      HCMAX7219.Refresh();
      delay(period);
            i = Position/11;
        lcd.setCursor(i,1);
      lcd.print("->>>>");

    }
      for(Position=0; Position <= 144; Position++)
    {
      HCMAX7219.printMatrix("2.ROBOTIC ARM", Position);
      HCMAX7219.Refresh();
      delay(period);
            i = Position/10;
        lcd.setCursor(i,1);
      lcd.print("->>>>");

    }  
}
