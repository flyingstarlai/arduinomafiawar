#include "Arduino.h"
#include "GameScreen.h"
#include "GameObject.h"


GameScreen*  GameScreen::s_instance = NULL;

GameScreen* GameScreen::getInstance() {
  if (!s_instance)
    s_instance = new GameScreen;
  return s_instance;
}

void GameScreen::Init(LiquidCrystal_I2C* lcd) {
  _DEBUG = false;


 
  _lcd = lcd;
  _lcd->begin(20, 4);
  if(_DEBUG) {
    Serial.print(F("Initialize LCD"));
  }

}



void GameScreen::Print(String words, uint8_t x, uint8_t y) {
  _lcd->setCursor(x, y); //Start at character 4 on line 0
  _lcd->print(words);
}

void GameScreen::Clear() {
  _lcd->clear();
}

void GameScreen::Draw(uint8_t character, uint8_t x, uint8_t y) {
    switch(character) {
        case TITLE_ANIM_1:
            _drawTitleA1(x, y);
            break;
        case TITLE_ANIM_2:
            _drawTitleA2(x, y);
            break;
        case KAISHI:
            _drawKaishi(x, y);
            break;
        case SLIME_ANIM_1:
            _drawSlimeA1(x, y);
            break;
        case SLIME_ANIM_2:
            _drawSlimeA2(x, y);
            break;
        case SKULL:
            _drawSkull(x, y);
            break;
        case GUN_BIG:
            _drawGunBig(x, y);
            break;
        case BUTTONUP:
            _drawButton(x, y);
            break;
        case BUTTONDOWN:
            _drawButtonDown(x, y);
            break;
        case DEATH:
            _drawDeath(x, y);
            break;
        case FLAG_ANIM_1:
            _drawFlagA1(x, y);
            break;
        case FLAG_ANIM_2:
            _drawFlagA2(x, y);
            break;
        case SAD:
            _drawSad(x, y);
            break;
       case MAFIAONE:
            _drawMafiaOne(x, y);
            break;  
        case MAFIATWO:
            _drawMafiaTwo(x, y);
            break;
        case TSU:
            _drawTSU(x, y);
            break;
        case WAR_BEGIN:
            _drawWarBegin(x, y);
            break;
    }
}


void GameScreen::_drawTitleA1(uint8_t x, uint8_t y) {
    _lcd->createChar(0, Title00); 
    _lcd->createChar(1, Title01); 
    _lcd->createChar(2, Title02); 
    _lcd->createChar(3, Title03);
    _lcd->createChar(4, Title10); 
    _lcd->createChar(5, Title11); 
    _lcd->createChar(6, Title12); 
    _lcd->createChar(7, Title13); 

    _lcd->setCursor(x, y);
    _lcd->write(byte(0));
    _lcd->write(byte(1));
    _lcd->write(byte(2));
    _lcd->write(byte(3));

    _lcd->setCursor(x, y+1);
    _lcd->write(byte(4));
    _lcd->write(byte(5));
    _lcd->write(byte(6));
    _lcd->write(byte(7));

    // _lcd->setCursor(x-2, y+2);
    // _lcd->print(F("MAFIAWAR"));




}


void GameScreen::_drawTitleA2(uint8_t x, uint8_t y) {

    _lcd->createChar(1, Title01A);
    _lcd->createChar(2, Title02A); 
    _lcd->createChar(6, Title12A); 


    _lcd->setCursor(x+1, y);
    _lcd->write(byte(1));
    _lcd->write(byte(2));

    _lcd->setCursor(x+2, y+1);
    _lcd->write(byte(6));


    // _lcd->setCursor(x-2, y+2);
    // _lcd->print(F("MAFIAWAR"));

  
}

void GameScreen::_drawKaishi(uint8_t x, uint8_t y) {

    _lcd->createChar(0, KaiLT); 
    _lcd->createChar(1, KaiRT); 
    _lcd->createChar(2, ShiLT); 
    _lcd->createChar(3, ShiRT);
    _lcd->createChar(4, KaiLB); 
    _lcd->createChar(5, KaiRB); 
    _lcd->createChar(6, ShiLB); 
    _lcd->createChar(7, ShiRB); 


    _lcd->setCursor(x, y);
    _lcd->write(byte(0));
    _lcd->write(byte(1));
    _lcd->write(byte(2));
    _lcd->write(byte(3));

    _lcd->setCursor(x, y+1);
    _lcd->write(byte(4));
    _lcd->write(byte(5));
    _lcd->write(byte(6));
    _lcd->write(byte(7));


}

void GameScreen::_drawSlimeA1(uint8_t x, uint8_t y) {
    _lcd->createChar(0, Slime00); 
    _lcd->createChar(1, Slime01); 
    _lcd->createChar(2, Slime02); 
    _lcd->createChar(3, Slime10);
    _lcd->createChar(4, Slime11); 
    _lcd->createChar(5, Slime12); 


    _lcd->setCursor(x, y);
    _lcd->write(byte(0));
    _lcd->write(byte(1));
    _lcd->write(byte(2));

    _lcd->setCursor(x, y+1);
    _lcd->write(byte(3));
    _lcd->write(byte(4));
    _lcd->write(byte(5));

}


void GameScreen::_drawSlimeA2(uint8_t x, uint8_t y) {
    _lcd->createChar(0, Slime00A); 
    _lcd->createChar(1, Slime01A); 
    _lcd->createChar(2, Slime02A); 
    _lcd->createChar(3, Slime10A);
    _lcd->createChar(4, Slime11A); 
    _lcd->createChar(5, Slime12A); 

    _lcd->setCursor(x, y);
    _lcd->write(byte(0));
    _lcd->write(byte(1));
    _lcd->write(byte(2));

    _lcd->setCursor(x, y+1);
    _lcd->write(byte(3));
    _lcd->write(byte(4));
    _lcd->write(byte(5));

}


void GameScreen::_drawSkull(uint8_t x, uint8_t y) {
    _lcd->createChar(0, Skull00); 
    _lcd->createChar(1, Skull01); 
    _lcd->createChar(2, Skull02); 
    _lcd->createChar(3, Skull03);
    _lcd->createChar(4, Skull10); 
    _lcd->createChar(5, Skull11); 
    _lcd->createChar(6, Skull12); 
    _lcd->createChar(7, Skull13); 

    _lcd->setCursor(x, y);
    _lcd->write(byte(0));
    _lcd->write(byte(1));
    _lcd->write(byte(2));
    _lcd->write(byte(3));

    _lcd->setCursor(x, y+1);
    _lcd->write(byte(4));
    _lcd->write(byte(5));
    _lcd->write(byte(6));
    _lcd->write(byte(7));


}


void GameScreen::_drawGunBig(uint8_t x, uint8_t y) {
    _lcd->createChar(0, Gun00); 
    _lcd->createChar(1, Gun01); 
    _lcd->createChar(2, Gun02); 
    _lcd->createChar(3, Gun03);
    _lcd->createChar(4, Gun10); 
    _lcd->createChar(5, Gun11); 
    _lcd->createChar(6, Gun12); 
    _lcd->createChar(7, Gun13); 

    _lcd->setCursor(x, y);
    _lcd->write(byte(0));
    _lcd->write(byte(1));
    _lcd->write(byte(2));
    _lcd->write(byte(3));

    _lcd->setCursor(x, y+1);
    _lcd->write(byte(4));
    _lcd->write(byte(5));
    _lcd->write(byte(6));
    _lcd->write(byte(7));

}


void GameScreen::_drawButton(uint8_t x, uint8_t y) {
    _lcd->createChar(0, Button00); 
    _lcd->createChar(1, Button01); 
    _lcd->createChar(2, Button10); 
    _lcd->createChar(3, Button11); 

    _lcd->setCursor(x, y);
    _lcd->write(byte(0));
    _lcd->write(byte(1));
    _lcd->setCursor(x, y+1);
    _lcd->write(byte(2));
    _lcd->write(byte(3)); 

}

void GameScreen::_drawButtonDown(uint8_t x, uint8_t y) {
    _lcd->createChar(4, ButtonDown00); 
    _lcd->createChar(5, ButtonDown01); 
    _lcd->createChar(6, ButtonDown10); 
    _lcd->createChar(7, ButtonDown11); 

    _lcd->setCursor(x, y);
    _lcd->write(byte(4));
    _lcd->write(byte(5));
    _lcd->setCursor(x, y+1);
    _lcd->write(byte(6));
    _lcd->write(byte(7)); 

}


void GameScreen::_drawDeath(uint8_t x, uint8_t y) {
    _lcd->createChar(0, Death00); 
    _lcd->createChar(1, Death01); 
    _lcd->createChar(2, Death02); 
    _lcd->createChar(3, Death03);
    _lcd->createChar(4, Death10); 
    _lcd->createChar(5, Death11); 
    _lcd->createChar(6, Death12); 
    _lcd->createChar(7, Death13); 

    _lcd->setCursor(x, y);
    _lcd->write(byte(0));
    _lcd->write(byte(1));
    _lcd->write(byte(2));
    _lcd->write(byte(3));

    _lcd->setCursor(x, y+1);
    _lcd->write(byte(4));
    _lcd->write(byte(5));
    _lcd->write(byte(6));
    _lcd->write(byte(7));

}


void GameScreen::_drawFlagA1(uint8_t x, uint8_t y) {
    _lcd->createChar(0, Flag00); 
    _lcd->createChar(1, Flag01); 
    _lcd->createChar(2, Flag02); 
    _lcd->createChar(3, Flag03);
    _lcd->createChar(4, Flag10); 
    _lcd->createChar(5, Flag11); 
    _lcd->createChar(6, Flag12); 
    _lcd->createChar(7, Flag13); 

    _lcd->setCursor(x, y);
    _lcd->write(byte(0));
    _lcd->write(byte(1));
    _lcd->write(byte(2));
    _lcd->write(byte(3));

    _lcd->setCursor(x, y+1);
    _lcd->write(byte(4));
    _lcd->write(byte(5));
    _lcd->write(byte(6));
    _lcd->write(byte(7));

}


void GameScreen::_drawFlagA2(uint8_t x, uint8_t y) {
    _lcd->createChar(0, Flag00A);  
    _lcd->createChar(3, Flag03A);
    _lcd->createChar(6, Flag12A); 
    _lcd->createChar(7, Flag13A); 

    _lcd->setCursor(x, y);
    _lcd->write(byte(0));
    _lcd->setCursor(x+3, y);
    _lcd->write(byte(3));

    _lcd->setCursor(x+2, y+1);
    _lcd->write(byte(6));
    _lcd->setCursor(x+3, y+1);
    _lcd->write(byte(7));

}

void GameScreen::_drawSad(uint8_t x, uint8_t y) {
    _lcd->createChar(0, Sad00); 
    _lcd->createChar(1, Sad01); 
    _lcd->createChar(2, Sad02); 
    _lcd->createChar(3, Sad03);
    _lcd->createChar(4, Sad10); 
    _lcd->createChar(5, Sad11); 
    _lcd->createChar(6, Sad12); 
    _lcd->createChar(7, Sad13); 

    _lcd->setCursor(x, y);
    _lcd->write(byte(0));
    _lcd->write(byte(1));
    _lcd->write(byte(2));
    _lcd->write(byte(3));

    _lcd->setCursor(x, y+1);
    _lcd->write(byte(4));
    _lcd->write(byte(5));
    _lcd->write(byte(6));
    _lcd->write(byte(7));

}


void GameScreen::_drawMafiaOne(uint8_t x, uint8_t y) {
    _lcd->createChar(0, MafiaOne00); 
    _lcd->createChar(1, MafiaOne01); 
    _lcd->createChar(2, MafiaOne10); 
    _lcd->createChar(3, MafiaOne11); 

    _lcd->setCursor(x, y);
    _lcd->write(byte(0));
    _lcd->write(byte(1));

    _lcd->setCursor(x, y+1);
    _lcd->write(byte(2));
    _lcd->write(byte(3));

}

void GameScreen::_drawMafiaTwo(uint8_t x, uint8_t y) {
    _lcd->createChar(4, MafiaTwo00); 
    _lcd->createChar(5, MafiaTwo01); 
    _lcd->createChar(6, MafiaTwo10); 
    _lcd->createChar(7, MafiaTwo11); 

    _lcd->setCursor(x, y);
    _lcd->write(byte(4));
    _lcd->write(byte(5));

    _lcd->setCursor(x, y+1);
    _lcd->write(byte(6));
    _lcd->write(byte(7));

}

void GameScreen::_drawTSU(uint8_t x, uint8_t y) {
    _lcd->createChar(0, TSU00); 
    _lcd->createChar(1, TSU01); 
    _lcd->createChar(2, TSU02); 
    _lcd->createChar(3, TSU03);
    _lcd->createChar(4, TSU10); 
    _lcd->createChar(5, TSU11); 
    _lcd->createChar(6, TSU12); 
    _lcd->createChar(7, TSU13); 

    _lcd->setCursor(x, y);
    _lcd->write(byte(0));
    _lcd->write(byte(1));
    _lcd->write(byte(2));
    _lcd->write(byte(3));

    _lcd->setCursor(x, y+1);
    _lcd->write(byte(4));
    _lcd->write(byte(5));
    _lcd->write(byte(6));
    _lcd->write(byte(7));

}

void GameScreen::_drawWarBegin(uint8_t x, uint8_t y) {
    _lcd->createChar(0, War00); 
    _lcd->createChar(1, War01); 
    _lcd->createChar(2, War02); 
    _lcd->createChar(3, War03);
    _lcd->createChar(4, War10); 
    _lcd->createChar(5, War11); 
    _lcd->createChar(6, War12); 
    _lcd->createChar(7, War13); 

    _lcd->setCursor(x, y);
    _lcd->write(byte(0));
    _lcd->write(byte(1));
    _lcd->write(byte(2));
    _lcd->write(byte(3));

    _lcd->setCursor(x, y+1);
    _lcd->write(byte(4));
    _lcd->write(byte(5));
    _lcd->write(byte(6));
    _lcd->write(byte(7));

}
