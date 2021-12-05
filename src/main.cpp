/*****************************************************************
 * Sharp PC-G850V(S) Interface
 * By: ChrisHerman
 * Date: December 5th, 2021
 *
 * Receives files from Sharp G850 and sends to PC via USB-Serial (Nano)
 * Requires G850's RTS and CTS lines to be connected witch each other 
 * and pulled-up to +5V. otherwise SHarp will wait forever.
 * 
 *
 * Hardware Hookup:
 * * 
 * Sharp G850 11 pin port     Arduino Nano
 *=========================================
 *  GND (pin 3) __________________ GND
 * 
 * Rx (pin 6)  __________________ GPIO9
 * 
 * Tx (pin 7)  __________________ GDIO8
 * 
 * RTS (pin 4) __________
 *                       |
 * CTS (pin 9) __________+
 *                       |
 * +5V         ---[10K]--+
 * 
 *
 * This code is released under the [MIT License](http://opensource.org/licenses/MIT).
 *****************************************************************/


#include <Arduino.h>
#include <SoftwareSerial.h>
#define RX_PIN 8
#define TX_PIN 9

SoftwareSerial SoftSerial(RX_PIN, TX_PIN, true); // RX, TX, inverse_logic = true

char c; // variable to store incoming data

void setup() {
  SoftSerial.begin(BAUDRATE);
  Serial.begin(BAUDRATE);
}

void loop() {

  if (Serial.available())  { // If data comes in from serial monitor (PC), send it out to softserial port
    SoftSerial.write(Serial.read());
  }
  if (SoftSerial.available())  { // If data comes in from softserial, send it out to serial monitor (PC)
    Serial.write(SoftSerial.read());
  }
}
