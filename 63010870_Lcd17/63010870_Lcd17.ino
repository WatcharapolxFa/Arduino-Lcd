//Prac 18 JATUPONG OBOUN 62010096
#include <Wire.h>
#include <hd44780.h> // main hd44780 header
#include <hd44780_I2Cexp.h> // i2c expander i/o class header
hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip
const int LCD_COLS = 16;
const int LCD_ROWS = 2;
int button = 0;
byte address , data, device = 0x27;

void setup()
{
int status;
status = lcd.begin(LCD_COLS, LCD_ROWS);
  if(status) // non zero status means it was unsuccesful
  {
  // begin() failed so blink error code using the onboard LED if possible
  hd44780::fatalError(status); // does not return
  }

  Serial.begin(9600);
  for(address = 1; address < 127; address++ ) // sets the value (range from 1 to 127)
{
    Wire.beginTransmission(address); // transmit to address
    if (Wire.endTransmission() == 0) // I2C devices found
    { device = address; }
} 
  Wire.begin();
  pinMode(4, INPUT_PULLUP);



}


void loop() {
  if (!digitalRead(4))
  {
    button = 1;
    Serial.println("2");
    Serial.println(button);
    delay(200);
   lcd.setCursor(0, 1);
    lcd.print("counterclockwise");
  } 
    else
   {
    button = -1;
    Serial.println("3");
    Serial.println(button);
    delay(200);
  lcd.clear();
  lcd.setCursor(3, 1);
    lcd.print("Clockwise");
  } 


  
  if(button==1){
    
    Wire.beginTransmission(device); // transmit to device
    Wire.write(0b10000000); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
    Wire.beginTransmission(device); // transmit to device
    Wire.write(0b10010000); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
    Wire.beginTransmission(device); // transmit to device
    Wire.write(0b00010000); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
    Wire.beginTransmission(device); // transmit to device
    Wire.write(0b00110000); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
    Wire.beginTransmission(device); // transmit to device
    Wire.write(0b00100000); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
    Wire.beginTransmission(device); // transmit to device
    Wire.write(0b01100000); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
    Wire.beginTransmission(device); // transmit to device
    Wire.write(0b01000000); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
    Wire.beginTransmission(device); // transmit to device
    Wire.write(0b11000000); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
    }

    else if(button==-1){
    Wire.beginTransmission(device); // transmit to device
    Wire.write(0b10000000); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
    Wire.beginTransmission(device); // transmit to device
    Wire.write(0b11000000); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
    Wire.beginTransmission(device); // transmit to device
    Wire.write(0b01000000); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
    Wire.beginTransmission(device); // transmit to device
    Wire.write(0b01100000); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
    Wire.beginTransmission(device); // transmit to device
    Wire.write(0b00100000); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
    Wire.beginTransmission(device); // transmit to device
    Wire.write(0b00110000); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
    Wire.beginTransmission(device); // transmit to device
    Wire.write(0b00010000); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
    Wire.beginTransmission(device); // transmit to device
    Wire.write(0b10010000); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
      }
  

    
}
