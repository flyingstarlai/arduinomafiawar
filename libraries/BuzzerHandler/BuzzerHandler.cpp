#include "Arduino.h"
#include "BuzzerHandler.h"
#include "GameObject.h"
#include "GameScreen.h"

BuzzerHandler*  BuzzerHandler::s_instance = NULL;

BuzzerHandler* BuzzerHandler::getInstance() {
    if (!s_instance)
        s_instance = new BuzzerHandler;
    return s_instance;
}

void BuzzerHandler::Init(uint8_t pin) {

    _DEBUG = true;
    pinMode(pin, OUTPUT);
    _pin = pin;
    _play = true;


    if(_DEBUG) {
        Serial.print(F("Initialize Buzzer at "));
        Serial.println(_pin);
    }


}

void BuzzerHandler::Buzz(uint8_t sound) {

    switch(sound) {
        case BUZZ_INTRO: 
            _playIntro(_introLength, _tempoModerete); 
            break;
        case BUZZ_COIN_INSERTED: 
            _playCoinInserted(_coinInsertedLength, _tempoSlow); 
            break;
        case BUZZ_ROULETTE: 
            _playRoulette(_rouletteLength, _tempoModerete); 
            break;
        case BUZZ_SLAP: 
            _playRoulette(_slapLength, _tempoFast); 
            break;
        case BUZZ_CLICK: 
            _playClick(_clickLength, _tempoFast); 
            break;
        case BUZZ_COMPARED: 
            _playCompared(_comparedLength, _tempoSlow); 
            break;
        case BUZZ_GOT_WEAPON: 
            _playGotWeapon(_gotWeaponLength, _tempoSlow); 
            break;
        case BUZZ_JAILED: 
            _playJailed(_jailedLength, _tempoModerete); 
            break;
        case BUZZ_KILLED_BY_BULL: 
            _playKilledByBull(_killedByBullLength, _tempoSlow); 
            break;
        case BUZZ_DRAW_SLAP: 
            _playRoulette(_drawSlapLength, _tempoFast); 
            break;
        case BUZZ_WAR_BEGIN: 
            _playWarBegin(_warBeginLength, _tempoSlow); 
            break;
        case BUZZ_ATTACK_MOVE: 
            _playAttackMove(_attackMoveLength, _tempoFast); 
            break;
        case BUZZ_GUARD_MOVE: 
            _playGuardMove(_guardMoveLength, _tempoFast); 
            break;
        case BUZZ_ATTACK_SUCCESS: 
            _playAttackSuccess(_attackSuccess, _tempoModerete); 
            break;
        case BUZZ_ATTACK_FAILED: 
            _playAttackFailed(_attackFailed, _tempoModerete); 
            break;
        case BUZZ_NEXT_ROUND: 
            _playNextRound(_nextRoundLength, _tempoFast); 
            break;
        case BUZZ_VICTORY: 
            _playVictory(_victoryLength, _tempoModerete); 
            break;
        case BUZZ_GAMEOVER: 
            _playGameOver(_victoryLength, _tempoFast); 
            break;    
    }

        
}



void BuzzerHandler::_playIntro(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {

        switch(i) {
            case 0: GameScreen::getInstance()->Print(F("TSU Game Design"), 2, 0); break;
            case 7: GameScreen::getInstance()->Print(F("present"), 6, 1); break;
            case 14: GameScreen::getInstance()->Print(F("Arduino Arcade Game"), 1, 3); break;
        }


        uint16_t duration = pgm_read_byte_near(INTRO_BEATS + i) * tempo;
        
        if (pgm_read_word_near(INTRO_NOTES + i) == ' ')
        {

            delay(duration);
        }
        else 
        {
           
            tone(_pin, _frequency(pgm_read_word_near(INTRO_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}



void BuzzerHandler::_playCoinInserted(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(COIN_INSERTED_BEATS + i) * tempo;
        if (pgm_read_word_near(COIN_INSERTED_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(COIN_INSERTED_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}


void BuzzerHandler::_playRoulette(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(ROULETTE_BEATS + i) * tempo;
        if (pgm_read_word_near(ROULETTE_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(ROULETTE_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}


void BuzzerHandler::_playSlap(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(SLAP_BEATS + i) * tempo;
        if (pgm_read_word_near(SLAP_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(SLAP_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}

void BuzzerHandler::_playClick(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(CLICK_BEATS + i) * tempo;
        if (pgm_read_word_near(CLICK_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(CLICK_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}

void BuzzerHandler::_playCompared(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(COMPARED_BEATS + i) * tempo;
        if (pgm_read_word_near(COMPARED_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(COMPARED_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}

void BuzzerHandler::_playGotWeapon(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(GOT_WEAPON_BEATS + i) * tempo;
        if (pgm_read_word_near(GOT_WEAPON_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(GOT_WEAPON_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}

void BuzzerHandler::_playJailed(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(JAILED_BEATS + i) * tempo;
        if (pgm_read_word_near(JAILED_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(JAILED_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}

void BuzzerHandler::_playKilledByBull(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(KILLED_BY_BULL_BEATS + i) * tempo;
        if (pgm_read_word_near(KILLED_BY_BULL_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(KILLED_BY_BULL_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}

void BuzzerHandler::_playDrawSlap(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(DRAW_SLAP_BEATS + i) * tempo;
        if (pgm_read_word_near(DRAW_SLAP_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(DRAW_SLAP_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}

void BuzzerHandler::_playWarBegin(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(WAR_BEGIN_BEATS + i) * tempo;
        if (pgm_read_word_near(WAR_BEGIN_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(WAR_BEGIN_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}

void BuzzerHandler::_playAttackMove(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(ATTACK_MOVE_BEATS + i) * tempo;
        if (pgm_read_word_near(ATTACK_MOVE_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(ATTACK_MOVE_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}

void BuzzerHandler::_playGuardMove(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(GUARD_MOVE_BEATS + i) * tempo;
        if (pgm_read_word_near(GUARD_MOVE_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(GUARD_MOVE_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}

void BuzzerHandler::_playAttackSuccess(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(ATTACK_SUCCESS_BEATS + i) * tempo;
        if (pgm_read_word_near(ATTACK_SUCCESS_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(ATTACK_SUCCESS_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}

void BuzzerHandler::_playAttackFailed(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(ATTACK_FAILED_BEATS + i) * tempo;
        if (pgm_read_word_near(ATTACK_FAILED_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(ATTACK_FAILED_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}

void BuzzerHandler::_playNextRound(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(NEXT_ROUND_BEATS + i) * tempo;
        if (pgm_read_word_near(NEXT_ROUND_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(NEXT_ROUND_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}



void BuzzerHandler::_playVictory(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(VICOTRY_BEATS + i) * tempo;
        if (pgm_read_word_near(VICOTRY_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(VICOTRY_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}


void BuzzerHandler::_playGameOver(uint8_t length, uint8_t tempo) {

    for (uint8_t i = 0; i < length; i++) 
    {
        uint16_t duration = pgm_read_byte_near(GAMEOVER_BEATS + i) * tempo;
        if (pgm_read_word_near(GAMEOVER_NOTES + i) == ' ')
        {

            delay(duration); 
        }
        else 
        {
            tone(_pin, _frequency(pgm_read_word_near(GAMEOVER_NOTES + i)) , duration);
            delay(duration); 
        }
        
            delay(tempo/10); 
    }

}




uint16_t BuzzerHandler::_frequency(char note) {

 
  const int numNotes = 8; 
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  
  for (uint8_t i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(pgm_read_word_near(FREQUENCIES + i));     // Yes! Return the frequency
    }
  }

  return(0);  // We looked through everything and didn't find it,


}

