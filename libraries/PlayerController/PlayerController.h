#ifndef PlayerController_h
#define PlayerController_h

#include "GameEngine.h"
#include "Arduino.h"


class PlayerController
{
public:
	virtual void Init(uint16_t analogController) = 0;

	virtual void Slap(uint8_t time) = 0;

	virtual void Move(uint8_t bingo) = 0;

	virtual void Dead() = 0;


	virtual uint8_t readButton() = 0;


	virtual uint8_t getSlapRespond() = 0;

	virtual uint8_t getSlapTime() = 0;




protected:
	PlayerController() { }
};

#endif

