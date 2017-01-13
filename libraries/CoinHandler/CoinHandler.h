#ifndef CoinHandler_h
#define CoinHandler_h

#include "Arduino.h"


class CoinHandler
{
  public:
  	static CoinHandler* getInstance();

  	void Init(uint16_t analogPin, uint8_t pin);
  	bool Insert();
    void TurnIndicator(bool on);
  	
  protected:
	  CoinHandler(){}
  private:
  	static CoinHandler* s_instance;

  	bool _DEBUG;
  	uint16_t _analogPin;
    uint8_t _pin;
  	bool _inserted;

};

#endif