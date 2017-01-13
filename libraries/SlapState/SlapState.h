#ifndef SlapState_h
#define SlapState_h

#include "GameState.h"
#include <stdint.h>

enum Winslap {
	P1_WIN_WEAPON = 1,
	P2_WIN_WEAPON = 2,
	P1P2_LOSE_WEAPON = 3,
	P1_DODGE_BULL = 4,
	P2_DODGE_BULL = 5,
	P1P2_BULLED = 6,
	P1_ESCAPE_POLICE = 7,
	P2_ESCAPE_POLICE = 8,
	P1P2_JAILED = 9
};

enum ResponseTime {
	P1_FASTER = 1,
	P2_FASTER = 2
};

enum SlapRespond { 
	 SLAP_BLUE = 1, 
	 SLAP_RED = 2, 
	 SLAP_BOTH = 3,
	 P1SLAP = 11,
	 P2SLAP = 12
};

class SlapState : public GameState
{
public:
	void Init();
	void Cleanup();

	void HandleEvents();
	void Update();
	void Draw();

	


	static SlapState* getInstance();


protected:
	SlapState() { }
	~SlapState();

private:
	bool _DEBUG;
	void _doListen();
	void _doCompare(uint8_t p1Respond, uint8_t p2Respond);
	void _doResult();
	uint8_t _compareTime(uint8_t p1Timer, uint8_t p2Timer);
	uint8_t _drawBalancing();
	void _doChangeSatate();
	void _displayCompare(uint8_t player, uint8_t slap);
	void _displayResult();


	uint8_t _bingo;
	uint16_t _timer;
	uint8_t _subState;
	uint8_t _stateResult;


private:
	static SlapState* s_instance;

};

#endif

