#ifndef RouletteMachine_h
#define RouletteMachine_h

#include "Arduino.h"


class RouletteMachine
{
  public:
    static RouletteMachine* getInstance();
  	void Init(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint8_t pin5, uint8_t pin6);
    void Reset();
    int Roll();

    int Bingo() { return _real_bingo; }

    void LedOff();


   private:
      RouletteMachine(){};
     	void _illuminate(uint8_t i);
     	uint8_t _leds[6];
     	uint16_t _delay;
    	uint8_t _current_bingo;
    	uint8_t _real_bingo;
    	uint16_t _cap;

      bool _DEBUG;

      static RouletteMachine* s_instance;
};

#endif