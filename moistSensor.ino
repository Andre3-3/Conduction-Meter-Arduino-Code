

#include <Wire.h>                    //includes the Wire.h libary for arduino if program dosent compile you should check that you have this
#include <LiquidCrystal_I2C.h>       //includes the LiquidCrystal_I2c.h libary this is VERY IMPORTAINT make sure you only use the libary from this link 

                          
LiquidCrystal_I2C lcd(0x27, 16, 2);  //Set the LCD address to 0x27 for a 16 chars and 2 line display

float cond = 255;                    //Creates a float called cond which is used to store our conduction value

void setup()                         //This code runs when the system is turned on
{
  // initialize the LCD
  lcd.begin();                       //starts the lcd
  lcd.backlight();                   //turns the backlight on
  
  lcd.print(" Andre's Sensor");      //prints the text to the screen
  lcd.setCursor(0,1);                //moves the curser down to the second line
  lcd.print("    Booting!");         //prints booting on second line
  delay(2500);                       //waits 2.5 seconds
  lcd.clear();                       //clears the screeen
  lcd.print("  Designed For");       //prints the text to the lcd
  lcd.setCursor(0,1);                //moves the cursor down to second line
  lcd.print(" Kal Secondary");       //prints the text on the second line
  delay(2500);                       //waits 2.5 seconds
  
  lcd.clear();                       //clears the screen
  lcd.setCursor(0,0);                //probably unnessasary but moves the cursor to the first line
  lcd.print(" Rel Conduction");      //prints the text to first line
  digitalWrite(12,HIGH);             //sets pin 12 on the arduino nano high
}

void loop()                          //this loops continualy
{
  lcd.setCursor(0,1);                //sets the cursor to the second line
  cond = analogRead(0);              //sets the cond variable to the input of analog pin0
  lcd.print(cond/1023*100);          //Math stuff :) this just divides cond by 1023 to get a value from 0-1 then multiples it by 100 to get a percent
  lcd.print("%");                    //this adds a % sign to the end of our number
  delay(100);                        //waits 100 ms to smooth out lcd refresh
  lcd.print("          ");           //just prints spaces to clear the second line but not the top
}
