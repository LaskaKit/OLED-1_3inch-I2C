/*
* This example code for LaskaKit 1.3" SH1106 OLED i2c display
* is used with ESP32 DEVkit board.
*
* SDA - GPIO21
* SCL - GPIO22
*
* Made by (c) laskakit.cz 2022
*
* Libraries
* https://github.com/adafruit/Adafruit-GFX-Library
* https://github.com/adafruit/Adafruit_SH110X
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>     // https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_SH110X.h>  // https://github.com/adafruit/Adafruit_SH110X

#define DELAYTIME 1000
#define i2c_Address 0x3c

Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, -1); //Nastavý display


void setup() {
  Serial.begin(115200);
  while(!Serial);    // time to get serial running
           
  display.begin(i2c_Address, true); 
  display.clearDisplay(); 
  display.setTextColor(SH110X_WHITE); 
  display.setTextSize(1); 
}

void loop() {
  // put your main code here, to run repeatedly:
   display.setCursor(0,0);
   display.println((String)"Teplota: 25C");
   display.println((String)"Tlak: 950hPa");
   display.println((String)"Vlhkost: 65%");
   display.println((String)"Nadmorska vyska: 554m");
   display.display(); 
   delay(500);
   display.clearDisplay();
}  
