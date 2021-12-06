# PC-G850V-InvertedSerial
Arduino code for using SoftwareSerial to connect Sharp PC-G850V(S) via an Arduino Uno or Nano to a PC.

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
 * See https://youtu.be/HVVmPWCUGlw for details
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

<iframe width="560" height="315" src="https://www.youtube.com/embed/HVVmPWCUGlw" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>