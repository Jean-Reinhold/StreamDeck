#include <Arduino.h> 
#include <BleKeyboard.h> 

class Button { 
  public: 

  uint8_t specialKey; 
  uint8_t key; 
  uint8_t Name;  

  Button(uint8_t spKey, uint8_t k, uint8_t N) {
    specialKey = spKey;
    key = k; 
    Name = N; 
  }

  bool isPressed(){ 
    if (digitalRead(Name) == 0) {
      delay(250);
      return true; 
    }  
    else { 
      return false;
    }  
  } 

  void sendMacro(BleKeyboard keyboard) { 
    keyboard.press(key);
    keyboard.releaseAll();  
  }   
};