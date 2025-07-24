// Basic sketch for setting up stimulation trigger for OpenXstim
// For any queries please contact: md.malam@connect.polyu.hk
/*
Digital Pot Control
  * A pin connected to +5V
  * B pin connected to ground
  * SDI - to digital pin 11 (MOSI pin)
  * CLK - to digital pin 13 (SCK pin)
*/

#include <SPI.h>
#include <EEPROM.h>
#include "MCP4261.h"

/* On the Arduino, digital pin 10 connects to cs (chip select), digital pin 13 connects to sck (clock), digital pin 11 connects to sdi/sdo (data out), groud on the power pins connects to Vss & 5V on the power pins connects to Vdd, P0A connects to Vdd, P0B connects to Vss, P0W is the output (voltage divider) 

Max output voltage: 3.60V
Min output voltage: 0.12V */

// select, shutdown, &SPI === HW SPI UNO clock = 13, dataOut = 11

#define CS_pin 10
#define SD_pin 255 // not used

MCP4261 pot(CS_pin, SD_pin, &SPI);

String inputString = ""; // string to hold incoming data
bool stringComplete = false; // bool to indicate whether string is complete

uint16_t potVal = 0;

void setup() {
  // initialized serial
  Serial.begin(9600);
  // reserve 200 bytes for the input string
  inputString.reserve(200);

  SPI.begin();
  pot.begin();

  pot.setEEPROM(0, 0); // sets the EEPROM to 0 (can comment out after first iteration)
  pot.setValue(0, 0);

  Serial.println(potVal, DEC);
}

void loop() {

  if (stringComplete) {
    uint16_t targetVal = inputString.toInt();

    // if (targetVal >= 0 && targetVal < 257) { 
      Serial.print("Current target and pot values: ");
      Serial.print(targetVal, DEC);
      Serial.print(" ");
      Serial.println(potVal, DEC);

      Serial.print("A0 = ");
      Serial.println(analogRead(A0));

      pot.setValue(0, targetVal);
      
      potVal = targetVal;

      delay(10);
      pot.setEEPROM(0, potVal);
      delay(10);

      Serial.print("Final pot value: ");
      Serial.println(potVal, DEC);

      // clear the string 
      inputString = "";
      stringComplete = false;
    // }
  }
}


void serialEvent() {
  while (Serial.available()) {
    // get new byte
    char inChar = (char)Serial.read();
    // add it to the input string
    inputString += inChar;
    // if next char is a newline, we are done reading
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

/////////////////////////////////////////////////////////////////////////
/* May 18th (Arduino IDE code from Pulse.ino)*/

// #define Hz 10 // set your stimulation frequency
// #define burst 10 // set your pulse number in the burst

// #define LOGIC_IN1 5
// #define LOGIC_IN2 6
// void setup() {
//   pinMode(LED_BUILTIN, OUTPUT);
//   pinMode(LOGIC_IN1, OUTPUT);
//   pinMode(LOGIC_IN2, OUTPUT); 
// }
// void loop() {
//   for (int i=0; i<burst; i++) {
//     // positive phase
//     digitalWrite(LOGIC_IN1, LOW);
//     digitalWrite(LOGIC_IN2, HIGH);  
//     delayMicroseconds(5000);
    
//     // negetive phase
//     digitalWrite(LOGIC_IN1, HIGH);    
//     digitalWrite(LOGIC_IN2, LOW);
//     delayMicroseconds(5000);
//   }
  
//   // stimulation delay
//   digitalWrite(LOGIC_IN1, LOW);    
//   digitalWrite(LOGIC_IN2, LOW);  
//   delay(1000/Hz);
//   digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // toggle LED 
// }

