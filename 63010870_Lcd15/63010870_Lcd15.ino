#include <Wire.h>
#include <hd44780.h> // main hd44780 header
#include <hd44780_I2Cexp.h>
hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip
const int LCD_COLS = 16;
const int LCD_ROWS = 2;
int buttonPin1 = 2;
int buttonState = 0;

void setup()
{
  
   //lcd.lineWrap();
    Serial.begin(115200);
    pinMode(buttonPin1,INPUT);
}
void loop()
{
   buttonState = digitalRead(buttonPin1);
   //Serial.println(buttonState);
  
  
  uint8_t char0[8] =
  {
    0b01000,
  0b01110,
  0b00000,
  0b01110,
  0b00010,
  0b00010,
  0b01110,
  0b01110
        }; 
  uint8_t char1[8] = 
  {
  0b00000,
  0b00000,
  0b00000,
  0b11010,
  0b01100,
  0b01010,
  0b01010,
  0b01110};
  uint8_t char2[8] = {  
0b00000,
  0b00000,
  0b00000,
  0b01111,
  0b01100,
  0b00100,
  0b01100,
  0b01100};
  uint8_t char3[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b11010,
  0b11010,
  0b01110,
  0b01110,
  0b01010}; 
  uint8_t char4[8] = {
   0b00000,
 0b00000,
  0b00000,
  0b01111,
  0b00001,
  0b01111,
  0b01001,
  0b01101}; 
  int status;
  status = lcd.begin(LCD_COLS, LCD_ROWS);
   lcd.cursor(); // turn on cursor so you can see where it is row = 0;
  

if(status) // non zero status means it was unsuccesful
{
 // begin() failed so blink error code using the onboard LED if possible
 hd44780::fatalError(status); // does not return
}
  lcd.createChar(0, char0);
  lcd.createChar(1, char1);
  lcd.createChar(2, char2);
  lcd.createChar(3, char3);
  lcd.createChar(4, char4);
  
  lcd.clear();
  lcd.setCursor(16, 0);
  lcd.write(0); // write character 0
  lcd.write(1); // write
  lcd.write(2);
  lcd.write(3); 
  lcd.write(4); // write character 4 // write character 3
 
  lcd.noCursor();

  for(int i=0;i<22;i++)
  {
    Serial.println(digitalRead(buttonPin1));
    if(!digitalRead(buttonPin1)==LOW)
    {
     lcd.scrollDisplayLeft();
    }
    else
    {
        lcd.scrollDisplayRight(); 
       i = i-2;
    }
    delay(500);
   
  }
  
}
