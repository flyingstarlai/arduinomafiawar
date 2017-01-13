#ifndef MafiaOne_h
#define MafiaOne_h

#include "PlayerController.h"
#include "Arduino.h"

class MafiaOne : public PlayerController
{
public:
	void Init(uint16_t analogController);

	void Create(uint8_t mafias);

	void Slap(uint8_t time);

	void Move(uint8_t bingo);

	void Dead();

	void Weapon();

	void Reset();

	uint8_t Members( ) {return _mafiaMembers; }

	uint8_t readButton();

	uint8_t getSlapRespond() { return _slapRespond; }

	uint8_t getSlapTime() { return _slapTime; }

	bool checkSlapRespond(uint8_t bingo);

	uint8_t getMove() { return _move; }

	bool isAttacker() { return _attacker; }

	bool isAlive();




	static MafiaOne* getInstance();

protected:
	MafiaOne() { }

private:
	static MafiaOne* s_instance;

	bool _isEscaped();

	bool _isBlocked();

	bool _hasWeapon();

	bool _DEBUG;

  	uint8_t _gameController;

    uint8_t _mafiaMembers;

    uint8_t _slapRespond;
    uint8_t _slapTime;

    bool _attacker;
    uint8_t _move;
    uint8_t _moveCount;

};

#endif

