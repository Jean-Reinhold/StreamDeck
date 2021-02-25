#include <Arduino.h>
#include <BleKeyboard.h> 
#include <Button.h>
#include <stdio.h>

#define CAM1       21 
#define CAM2       22 
#define CAM3       23 
#define CAM4       19 
#define TRANS      18 
#define START_STOP 14 
#define MUTEPC     17 
#define MUTEMESA   16 

BleKeyboard keyboard; 

Button cam1(0, 0x31, CAM1);
Button cam2(0, 0x32, CAM2);
Button cam3(0, 0x33, CAM3 );
Button cam4(0, 0x34, CAM4);
Button trans(0,0x74, TRANS);
Button start_stop(0, 0x73, START_STOP); 
Button mutePC(0, 0x70, MUTEPC);
Button muteMesa(0, 0x6d, MUTEMESA);


void setup() {
  keyboard.begin();

  pinMode(CAM1,       INPUT_PULLUP);
  pinMode(CAM2,       INPUT_PULLUP);
  pinMode(CAM3,       INPUT_PULLUP);
  pinMode(CAM4,       INPUT_PULLUP);
  pinMode(TRANS,      INPUT_PULLUP);
  pinMode(START_STOP, INPUT_PULLUP);
  pinMode(MUTEPC,     INPUT_PULLUP);
  pinMode(MUTEMESA,   INPUT_PULLUP);
}

void loop() {
  if(keyboard.isConnected()) { 
    if (cam1.isPressed()) 
      cam1.sendMacro(keyboard);

    if (cam2.isPressed()) 
      cam2.sendMacro(keyboard);
    
    if (cam3.isPressed()) 
      cam3.sendMacro(keyboard);

    if (cam4.isPressed()) 
      cam4.sendMacro(keyboard);

    if (trans.isPressed()) 
      trans.sendMacro(keyboard);

    if (start_stop.isPressed()) 
      start_stop.sendMacro(keyboard);

    if (muteMesa.isPressed()) 
      muteMesa.sendMacro(keyboard);

    if (mutePC.isPressed()) 
      mutePC.sendMacro(keyboard);
  }
  else 
    delay(100);
}
