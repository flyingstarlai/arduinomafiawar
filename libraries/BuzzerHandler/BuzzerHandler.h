#ifndef BuzzerHandler_h
#define BuzzerHandler_h

#include "Arduino.h"
#include <avr/pgmspace.h>

const PROGMEM uint16_t FREQUENCIES [] = {262, 294, 330, 349, 392, 440, 494, 523};
const PROGMEM char FREQUENCY_NAMES [] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };

const PROGMEM char INTRO_NOTES [] = "ffgagf eefgfe ddefed ccedgfa ";
const PROGMEM uint8_t INTRO_BEATS [] =  {1,1,1,1,1,1,3,1,1,1,1,1,1,2,1,1,1,1,1,1,3,1,1,1,1,1,1,1,2};

const PROGMEM char CLICK_NOTES [] = "C"; 
const PROGMEM uint8_t CLICK_BEATS [] = {1};

const PROGMEM char COIN_INSERTED_NOTES [] = "da";
const PROGMEM uint8_t COIN_INSERTED_BEATS [] =  {1,4};

const PROGMEM char COMPARED_NOTES [] = "dg";
const PROGMEM uint8_t COMPARED_BEATS [] =  {1,4};

const PROGMEM char ROULETTE_NOTES [] = "cdefg "; 
const PROGMEM uint8_t ROULETTE_BEATS [] = {1,1,1,1,1};

const PROGMEM char SLAP_NOTES [] = "C"; 
const PROGMEM uint8_t SLAP_BEATS [] = {1};

const PROGMEM uint8_t GOT_WEAPON_NOTES [] = "cdefg e cdefg ed";
const PROGMEM uint8_t GOT_WEAPON_BEATS [] = {1,1,1,1,2,1,1,1,1,1,1,1,2,1,1,1};; //120

const PROGMEM char JAILED_NOTES [] = "Ca";
const PROGMEM uint8_t JAILED_BEATS [] = {2,2};

const PROGMEM char KILLED_BY_BULL_NOTES [] =  "ee eee eee eeef"; 
const PROGMEM uint8_t KILLED_BY_BULL_BEATS [] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}; //120

const PROGMEM char DRAW_SLAP_NOTES [] = "gfa";
const PROGMEM uint8_t DRAW_SLAP_BEATS [] = {1,1,1};

const PROGMEM char WAR_BEGIN_NOTES []  = "dd fga agf dcfec"; 
const PROGMEM uint8_t WAR_BEGIN_BEATS [] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}; //120

const PROGMEM char ATTACK_MOVE_NOTES [] = "f babC";
const PROGMEM uint8_t ATTACK_MOVE_BEATS [] = {1,1,1,1,1,2}; //160

const PROGMEM char GUARD_MOVE_NOTES [] = "gabag";
const PROGMEM uint8_t GUARD_MOVE_BEATS [] = {1,1,1,1,1}; //160

const PROGMEM char ATTACK_SUCCESS_NOTES[] = "gg bbCba ";
const PROGMEM uint8_t ATTACK_SUCCESS_BEATS[] = {1,1,1,2,1,2,1,4,2};

const PROGMEM char ATTACK_FAILED_NOTES [] = "gae gad gagfedc";
const PROGMEM uint8_t ATTACK_FAILED_BEATS [] = {1,1,3,1,1,1,3,1,1,1,1,1,1,1,1};

const PROGMEM char NEXT_ROUND_NOTES [] = "ccegfe ccegfed"; 
const PROGMEM uint8_t NEXT_ROUND_BEATS [] = {1,1,1,1,1,2,1,1,1,1,1,1,1,1,1}; //160

const PROGMEM char VICOTRY_NOTES[] = "CCCC a b CbC "; 
const PROGMEM uint8_t VICOTRY_BEATS[] = {1,1,1,3,1,2,1,2,1,1,1,3};

const PROGMEM char GAMEOVER_NOTES[] = "aCafdcdcdcdcdcdcdc";
const PROGMEM uint8_t GAMEOVER_BEATS[] =  {4,4,4,4,4,1,1,1,1,1,1,1,1,1,1,1,1,4};




enum Buzzers {
  BUZZ_INTRO,
  BUZZ_COIN_INSERTED,
  BUZZ_ROULETTE,
  BUZZ_SLAP,
  BUZZ_GOT_WEAPON,
  BUZZ_JAILED,
  BUZZ_KILLED_BY_BULL,
  BUZZ_DRAW_SLAP,
  BUZZ_WAR_BEGIN,
  BUZZ_ATTACK_MOVE,
  BUZZ_GUARD_MOVE,
  BUZZ_ATTACK_SUCCESS,
  BUZZ_ATTACK_FAILED,
  BUZZ_NEXT_ROUND,
  BUZZ_VICTORY,
  BUZZ_GAMEOVER,
  BUZZ_CLICK,
  BUZZ_COMPARED,
};

class BuzzerHandler
{
  public:
  	static BuzzerHandler* getInstance();

  	void Init(uint8_t pin);

  	void Buzz(uint8_t sound);

  protected:

  private:
    uint16_t _frequency(char note);

  	static BuzzerHandler* s_instance;

  	bool _DEBUG;

  	uint8_t _pin;
    bool _play;

    const uint8_t _tempoFast = 160;
    const uint8_t _tempoModerete = 150;
    const uint8_t _tempoSlow = 120;

    const uint8_t _introLength = 29;
    const uint8_t _coinInsertedLength = 2;
    const uint8_t _rouletteLength = 5;
    const uint8_t _slapLength = 1;
    const uint8_t _gotWeaponLength = 16;
    const uint8_t _jailedLength = 2;
    const uint8_t _killedByBullLength = 15;
    const uint8_t _drawSlapLength = 3;
    const uint8_t _warBeginLength = 16;
    const uint8_t _attackMoveLength = 6;
    const uint8_t _guardMoveLength = 5;
    const uint8_t _attackFailed = 15;
    const uint8_t _attackSuccess = 9;
    const uint8_t _victoryLength = 12;
    const uint8_t _nextRoundLength = 15;
    const uint8_t _clickLength = 1;
    const uint8_t _comparedLength = 2;

    void _playIntro(uint8_t length, uint8_t tempo);

    void _playRoulette(uint8_t length, uint8_t tempo);

    void _playSlap(uint8_t length, uint8_t tempo);

    void _playCoinInserted(uint8_t length, uint8_t tempo); 

    void _playGotWeapon(uint8_t length, uint8_t tempo); 

    void _playJailed(uint8_t length, uint8_t tempo); 

    void _playKilledByBull(uint8_t length, uint8_t tempo); 

    void _playDrawSlap(uint8_t length, uint8_t tempo); 

    void _playWarBegin(uint8_t length, uint8_t tempo); 

    void _playAttackMove(uint8_t length, uint8_t tempo);

    void _playGuardMove(uint8_t length, uint8_t tempot); 

    void _playAttackSuccess(uint8_t length, uint8_t tempo); 

    void _playAttackFailed(uint8_t length, uint8_t tempo); 

    void _playNextRound(uint8_t length, uint8_t tempo);

    void _playVictory(uint8_t length, uint8_t tempo);

    void _playGameOver(uint8_t length, uint8_t tempo);

    void _playClick(uint8_t length, uint8_t tempo);

    void _playCompared(uint8_t length, uint8_t tempo);

};

#endif