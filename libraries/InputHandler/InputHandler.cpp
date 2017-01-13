#include "Arduino.h"
#include "InputHandler.h"
#include "GameObject.h"


InputHandler*  InputHandler::s_instance = NULL;

InputHandler* InputHandler::getInstance() {
  if (!s_instance)
    s_instance = new InputHandler;
  return s_instance;
}

void InputHandler::Init(uint16_t controller1, uint16_t controller2) {
  
  _DEBUG = true;

  pinMode(controller1, INPUT_PULLUP);
	pinMode(controller2, INPUT_PULLUP);

  if(_DEBUG) {
    Serial.print(F("Initialize Controller with analog "));
    Serial.print(controller1);
    Serial.print(F(" and "));
    Serial.println(controller2);
  }



}

uint16_t InputHandler::readInput(uint8_t pin) {
  uint8_t button;
  uint16_t readPin = 0;

	readPin = analogRead(pin);
	// Serial.print("READ PIN: ");
 //  Serial.println(readPin);

    if (readPin > 1000)
  		button = NONE; 
    else if (readPin > 210 && readPin < 250)
     	button = RED; // red button pressed
    else if (readPin > 120 && readPin < 160)
    	button = BLUE; // blue button pressed
    else if (readPin > 80 && readPin < 110)
     	button = BOTH; // both button pressed
           
  	return button;

}