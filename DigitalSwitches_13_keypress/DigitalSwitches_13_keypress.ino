/**************************************************************************
   Digital Switch Example - 13 switches with LED response and keypresses

   Up to 13 switches can be connected to pins D0-D12.

   Can be used to control the game Patatap: https://patatap.com/

   Adapted from:

   Tactile Interfaces Workshop for IMA Low Res Program - August 14, 2020
   https://gist.github.com/katehartman/9b728a8a34087604a383126a53d1d5f5

   Body-Centric Game Controller Workshop by Social Body Lab
   https://github.com/socialbodylab/Body-Centric-Game-Controllers/tree/master/BodyCentricGameControllers_Experiment1

   Arduino Example code:
   https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardwrite/
   https://www.arduino.cc/en/Reference/KeyboardModifiers

   Keyboard Ascii References:
   http://www.asciitable.com/

**************************************************************************/


#include <Keyboard.h>

const int switchNumber = 13;
//when changing this value, put the same number of zeroes in switchValue[] below

int switchValue[] = {
  // same number of zeros as switchNumber
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  // set pins D0-D12 as inputs and use the pullup resistor
  for (int i = 0; i < switchNumber; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  // set pin D13 as output so on-board LED can be used.
  pinMode(13, OUTPUT);
}

void loop() {
  // read each switch and if it is pressed...
  for (int i = 0; i < switchNumber; i++) {

    switchValue[i] = digitalRead(i);

    // fix print out for sensor values vs. key press

    if (switchValue[i] == LOW)  {
      // print the pin number to the Serial Monitor

      Serial.println(i);
      // send a letter key press. See ASCII table to decode: http://www.asciitable.com/
      Keyboard.write(97 + i);
      // turn on the onboard LED
      digitalWrite(13, HIGH);
      // wait (in milliseconds) to prevent rapidly pressing the key repeatedly
      delay(500);
      // turn off onboard LED
      digitalWrite(13, LOW);
    }
  }

  // delay in between reads for stability
  delay(100);

}
