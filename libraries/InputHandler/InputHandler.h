#ifndef InputHandler_h
#define InputHandler_h

#include "Arduino.h"


class InputHandler
{
  public:
  	static InputHandler* getInstance();

  	void Init(uint16_t controller1, uint16_t controller2);
  	uint16_t readInput(uint8_t pin);
  	
  private:
  	InputHandler(){};

  	static InputHandler* s_instance;

  	bool _DEBUG;

};

#endif