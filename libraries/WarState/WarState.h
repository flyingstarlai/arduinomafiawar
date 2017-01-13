#ifndef WarState_h
#define WarState_h

#include "GameState.h"

enum WarResult {
	P1_ATTACK_SUCCESS = 1,
	P1_ATTACK_FAILED = 2, 
	P2_ATTACK_SUCCESS = 3,
	P2_ATTACK_FAILED = 4,
};

enum Attacker {
	ATTACKER_IS_P1 = 1,
	ATTACKER_IS_P2 = 2
};

enum WarMove {
	LEFT = 1,
	RIGHT = 2,
	CENTER = 3,
	P1MOVE = 11,
	P2MOVE = 12
};


class WarState : public GameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents();
	void Update();
	void Draw();


	static WarState* getInstance();

protected:
	WarState() { }

private:
	bool _DEBUG;
	static WarState* s_instance;

	uint8_t _attacker;
	uint8_t _timer;

	uint8_t _subState;
	uint8_t _stateResult;

	void _doListen();
	void _doCompare(uint8_t p1Move, uint8_t p2Move);
	void _doResult();
	void _doChangeSatate();
	void _displayCompare(uint8_t player, uint8_t move);
	void _displayResult();



};

#endif

