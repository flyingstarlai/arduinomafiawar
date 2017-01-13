#ifndef GameScreen_h
#define GameScreen_h

#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include <avr/pgmspace.h>

     //Title00
const PROGMEM char Title00[8] = {
    0b00100,
    0b01110,
    0b11111,
    0b10101,
    0b11111,
    0b10101,
    0b11111,
    0b10101
};

//Title01
const PROGMEM char Title01[8] = {
    0b00111,
    0b01111,
    0b11111,
    0b01111,
    0b01110,
    0b01110,
    0b01111,
    0b00111
};

//Title01A
const PROGMEM char Title01A[8] = {
    0b00111,
    0b01111,
    0b11111,
    0b01111,
    0b01101,
    0b01101,
    0b01111,
    0b00111
};

//Title02
const PROGMEM char Title02[8] = {
    0b11100,
    0b11110,
    0b11111,
    0b11110,
    0b11010,
    0b11010,
    0b11110,
    0b11100
};

//Titile02A
const PROGMEM char Title02A[8] = {
    0b11100,
    0b11110,
    0b11111,
    0b11110,
    0b10110,
    0b10110,
    0b11110,
    0b11100
};

//Title03
const PROGMEM char Title03[8] = {
    0b00100,
    0b01000,
    0b01000,
    0b11010,
    0b11100,
    0b11000,
    0b11000,
    0b01110
};

//Title10
const PROGMEM char Title10[8] = {
    0b11111,
    0b11011,
    0b11011,
    0b11011,
    0b00000,
    0b00011,
    0b00011,
    0b00010
};

//Title11
const PROGMEM char Title11[8] = {
    0b00111,
    0b00111,
    0b00011,
    0b11000,
    0b11110,
    0b11111,
    0b11111,
    0b01111
};

//Title12
const PROGMEM char Title12[8] = {
    0b01100,
    0b11100,
    0b11000,
    0b00011,
    0b01111,
    0b11111,
    0b11111,
    0b11110
};

//Title12A
const PROGMEM char Title12A[8] = {
    0b11100,
    0b11100,
    0b11000,
    0b00011,
    0b01111,
    0b11111,
    0b11111,
    0b11110
};

//Title13
const PROGMEM char Title13[8] = {
    0b01110,
    0b11100,
    0b11110,
    0b01000,
    0b00000,
    0b00000,
    0b00000,
    0b00000
};



//Slime00
const PROGMEM char Slime00[8] = {
    0b01000,
    0b10100,
    0b01000,
    0b00101,
    0b00010,
    0b00101,
    0b00000,
    0b00001
};

//Slime01
const PROGMEM char Slime01[8] = {
    0b00000,
    0b00000,
    0b00001,
    0b00011,
    0b00010,
    0b00110,
    0b01100,
    0b10000
};

//Slime02
const PROGMEM char Slime02[8] = {
    0b00000,
    0b00000,
    0b10000,
    0b11000,
    0b01100,
    0b00100,
    0b00100,
    0b00100
};

//Slime10
const PROGMEM char Slime10[8] = {
    0b00010,
    0b00110,
    0b01100,
    0b01000,
    0b01000,
    0b01000,
    0b01110,
    0b00011
};

//Slime11
const PROGMEM char Slime11[8] = {
    0b01101,
    0b01001,
    0b00000,
    0b00000,
    0b00000,
    0b00001,
    0b00011,
    0b11110
};

//Slime12
const PROGMEM char Slime12[8] = {
    0b10100,
    0b00100,
    0b01100,
    0b01000,
    0b11000,
    0b00000,
    0b00000,
    0b00000
};

//Slime00A
const PROGMEM char Slime00A[8] = {
    0b00101,
    0b00010,
    0b00101,
    0b01000,
    0b10100,
    0b01001,
    0b00010,
    0b00010
};

//Slime01A
const PROGMEM char Slime01A[8] = {
    0b00011,
    0b00100,
    0b00100,
    0b01100,
    0b11000,
    0b10000,
    0b00000,
    0b11011
};

//Slime02A
const PROGMEM char Slime02A[8] = {
    0b00000,
    0b00000,
    0b10000,
    0b11000,
    0b01000,
    0b01000,
    0b01000,
    0b01000
};

//Slime10A
const PROGMEM char Slime10A[8] = {
    0b00010,
    0b00110,
    0b00100,
    0b00100,
    0b00100,
    0b00100,
    0b00110,
    0b00011
};

//Slime11A
const PROGMEM char Slime11A[8] = {
    0b10010,
    0b00000,
    0b00000,
    0b00000,
    0b00001,
    0b00001,
    0b00011,
    0b11110
};

//Slime12A
const PROGMEM char Slime12A[8] = {
    0b01000,
    0b01000,
    0b11000,
    0b10000,
    0b00000,
    0b00000,
    0b00000,
    0b00000
};



//kai kiri atas
const PROGMEM char KaiLT[8] = {
    0b11111,
    0b10001,
    0b10001,
    0b11111,
    0b10001,
    0b10001,
    0b11111,
    0b10000
};

//kai kiri bawah
const PROGMEM char KaiLB[8] = {
    0b10000,
    0b10111,
    0b10010,
    0b10011,
    0b10010,
    0b10100,
    0b10000,
    0b10000
};

//kai kanan atas
const PROGMEM char KaiRT[8] = {
    0b01111,
    0b01001,
    0b01001,
    0b01111,
    0b01001,
    0b01001,
    0b01111,
    0b00001
};

//kai kanan bawah
const PROGMEM char KaiRB[8] = {
    0b00001,
    0b11101,
    0b01001,
    0b11001,
    0b01001,
    0b01001,
    0b00001,
    0b00001
};


//shi kiri atas
const PROGMEM char ShiLT[8] = {
    0b00010,
    0b00100,
    0b11111,
    0b01001,
    0b01001,
    0b01001,
    0b11001,
    0b10010
};

//shi kiri bawah
const PROGMEM char ShiLB[8] = {
    0b10010,
    0b10010,
    0b01010,
    0b00100,
    0b00110,
    0b01001,
    0b10000,
    0b00000
};

//shi kanan atas
const PROGMEM char ShiRT[8] = {
    0b00010,
    0b00100,
    0b01000,
    0b10000,
    0b10000,
    0b10001,
    0b11111,
    0b00000
};

//shi kanan bawah
const PROGMEM char ShiRB[8] = {
    0b00000,
    0b11111,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b11111,
    0b00000
};



//Skull00
const PROGMEM char Skull00[8] = {
    0b11100,
    0b01010,
    0b00101,
    0b00010,
    0b00001,
    0b00000,
    0b00000,
    0b00000
};

//Skull01
const PROGMEM char Skull01[8] = {
    0b00000,
    0b01111,
    0b10000,
    0b10000,
    0b10111,
    0b10101,
    0b10110,
    0b10000
};

//Skull02
const PROGMEM char Skull02[8] = {
    0b00000,
    0b11110,
    0b00001,
    0b00001,
    0b11101,
    0b10101,
    0b01101,
    0b00001
};

//Skull03
const PROGMEM char Skull03[8] = {
    0b00111,
    0b01010,
    0b10100,
    0b01000,
    0b10000,
    0b00000,
    0b00000,
    0b00000
};

//Skull10
const PROGMEM char Skull10[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00001,
    0b00010,
    0b00101,
    0b01010,
    0b11100
};

//Skull11
const PROGMEM char Skull11[8] = {
    0b10000,
    0b01010,
    0b01011,
    0b01011,
    0b01111,
    0b00100,
    0b00000,
    0b00000
};

//Skull12
const PROGMEM char Skull12[8] = {
    0b00001,
    0b01010,
    0b11010,
    0b11010,
    0b11110,
    0b00100,
    0b00000,
    0b00000
};

//Skull13
const PROGMEM char Skull13[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b10000,
    0b01000,
    0b10100,
    0b01010,
    0b00111
};


//Gun00
const PROGMEM char Gun00[8] = {
    0b00000,
    0b00000,
    0b01111,
    0b11011,
    0b10011,
    0b11110,
    0b10000,
    0b10000
};

//Gun01
const PROGMEM char Gun01[8] = {
    0b00000,
    0b00111,
    0b11111,
    0b11111,
    0b11110,
    0b01010,
    0b01010,
    0b00010
};

//Gun02
const PROGMEM char Gun02[8] = {
    0b00000,
    0b11110,
    0b11111,
    0b11111,
    0b01000,
    0b01100,
    0b00111,
    0b00000
};

//Gun03
const PROGMEM char Gun03[8] = {
    0b00001,
    0b00111,
    0b11110,
    0b11110,
    0b00000,
    0b00000,
    0b00000,
    0b00000
};

//Gun10
const PROGMEM char Gun10[8] = {
    0b01000,
    0b01100,
    0b01111,
    0b01111,
    0b00000,
    0b00000,
    0b00000,
    0b00000
};

//Gun11
const PROGMEM char Gun11[8] = {
    0b00000,
    0b00111,
    0b11111,
    0b11111,
    0b00000,
    0b00000,
    0b00000,
    0b00000
};

//Gun12
const PROGMEM char Gun12[8] = {
    0b00000,
    0b11110,
    0b11111,
    0b11111,
    0b00010,
    0b00010,
    0b00001,
    0b00000
};

//Gun13
const PROGMEM char Gun13[8] = {
    0b00011,
    0b00010,
    0b11111,
    0b11111,
    0b01111,
    0b00111,
    0b11111,
    0b00011
};


//Button00
const PROGMEM char Button00[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00111,
    0b01000,
    0b10000,
    0b10000,
    0b10000
};

//Button01
const PROGMEM char Button01[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b11100,
    0b00010,
    0b00001,
    0b00001,
    0b00001
};

//Button10
const PROGMEM char Button10[8] = {
    0b10000,
    0b10000,
    0b10000,
    0b01000,
    0b00111,
    0b00000,
    0b00000,
    0b00000
};

//Button11
const PROGMEM char Button11[8] = {
    0b00001,
    0b00001,
    0b00001,
    0b00010,
    0b11100,
    0b00000,
    0b00000,
    0b00000
};

//ButtonDown00
const PROGMEM char ButtonDown00[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00111,
    0b01000,
    0b10111,
    0b10111,
    0b10111
};

//ButtonDown01
const PROGMEM char ButtonDown01[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b11100,
    0b00010,
    0b11101,
    0b11101,
    0b11101
};

//ButtonDown10
const PROGMEM char ButtonDown10[8] = {
    0b10111,
    0b10111,
    0b10111,
    0b01000,
    0b00111,
    0b00000,
    0b00000,
    0b00000
};

//ButtonDown11
const PROGMEM char ButtonDown11[8] = {
    0b11101,
    0b11101,
    0b11101,
    0b00010,
    0b11100,
    0b00000,
    0b00000,
    0b00000
};

//Death00
const PROGMEM char Death00[8] = {
    0b00000,
    0b00011,
    0b00011,
    0b00011,
    0b00011,
    0b11111,
    0b11111,
    0b00011
};

//Death01
const PROGMEM char Death01[8] = {
    0b00000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b11110,
    0b11110,
    0b10000
};

//Death02
const PROGMEM char Death02[8] = {
    0b00001,
    0b00001,
    0b00001,
    0b00001,
    0b01111,
    0b01111,
    0b00001,
    0b00001
};

//Death03
const PROGMEM char Death03[8] = {
    0b11000,
    0b11000,
    0b11000,
    0b11000,
    0b11111,
    0b11111,
    0b11000,
    0b11000
};

//Death10
const PROGMEM char Death10[8] = {
    0b00011,
    0b00011,
    0b00011,
    0b00011,
    0b00011,
    0b00011,
    0b00011,
    0b00011
};

//Death11
const PROGMEM char Death11[8] = {
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000
};

//Death12
const PROGMEM char Death12[8] = {
    0b00001,
    0b00001,
    0b00001,
    0b00001,
    0b00001,
    0b00001,
    0b00001,
    0b00000
};

//Death13
const PROGMEM char Death13[8] = {
    0b11000,
    0b11000,
    0b11000,
    0b11000,
    0b11000,
    0b11000,
    0b11000,
    0b00000
};
     
//Flag00
const PROGMEM char Flag00[8] = {
    0b01000,
    0b10100,
    0b01000,
    0b00000,
    0b00010,
    0b00101,
    0b01000,
    0b01000
};

//Flag00A
const PROGMEM char Flag00A[8] = {
    0b00000,
    0b00000,
    0b10100,
    0b01000,
    0b10110,
    0b00101,
    0b01000,
    0b01000
};

//Flag01
const PROGMEM char Flag01[8] = {
    0b00000,
    0b00000,
    0b00001,
    0b01110,
    0b10000,
    0b00000,
    0b00000,
    0b00000
};

//Flag02
const PROGMEM char Flag02[8] = {
    0b00000,
    0b00000,
    0b10010,
    0b01101,
    0b00001,
    0b00000,
    0b00000,
    0b00000
};

//Flag03
const PROGMEM char Flag03[8] = {
    0b00000,
    0b00100,
    0b01010,
    0b00100,
    0b00000,
    0b10101,
    0b10010,
    0b01101
};

//Flag03A
const PROGMEM char Flag03A[8] = {
    0b00000,
    0b00000,
    0b00100,
    0b01010,
    0b00100,
    0b11010,
    0b10100,
    0b01010
};

//Flag10
const PROGMEM char Flag10[8] = {
    0b00100,
    0b00100,
    0b00010,
    0b00001,
    0b00001,
    0b00000,
    0b00000,
    0b00000
};

//Flag11
const PROGMEM char Flag11[8] = {
    0b00000,
    0b00011,
    0b01100,
    0b10000,
    0b00000,
    0b10000,
    0b01000,
    0b01000
};

//Flag12
const PROGMEM char Flag12[8] = {
    0b00000,
    0b00011,
    0b11100,
    0b00000,
    0b01000,
    0b10100,
    0b01000,
    0b00000
};

//Flag12A
const PROGMEM char Flag12A[8] = {
    0b00000,
    0b00011,
    0b11100,
    0b00000,
    0b10100,
    0b01000,
    0b10100,
    0b00000
};

//Flag13
const PROGMEM char Flag13[8] = {
    0b00010,
    0b00100,
    0b11000,
    0b00000,
    0b00000,
    0b01010,
    0b00100,
    0b01010
};

//Flag13A
const PROGMEM char Flag13A[8] = {
    0b00010,
    0b00100,
    0b11000,
    0b01000,
    0b10100,
    0b01000,
    0b00000,
    0b00000
};


//Sad00
const PROGMEM char Sad00[8] = {
    0b00000,
    0b00001,
    0b00011,
    0b00100,
    0b01000,
    0b01000,
    0b01000,
    0b01000
};

//Sad01
const PROGMEM char Sad01[8] = {
    0b01111,
    0b10000,
    0b00000,
    0b01100,
    0b11110,
    0b10010,
    0b10110,
    0b01100
};

//Sad02
const PROGMEM char Sad02[8] = {
    0b11110,
    0b00001,
    0b00000,
    0b00110,
    0b01111,
    0b01001,
    0b01011,
    0b00110
};

//Sad03
const PROGMEM char Sad03[8] = {
    0b00000,
    0b11000,
    0b00101,
    0b10101,
    0b10001,
    0b10101,
    0b10100,
    0b00100
};

//Sad10
const PROGMEM char Sad10[8] = {
    0b01000,
    0b01000,
    0b01000,
    0b01000,
    0b00100,
    0b00100,
    0b00011,
    0b00000
};

//Sad11
const PROGMEM char Sad11[8] = {
    0b00000,
    0b00000,
    0b00011,
    0b00100,
    0b01100,
    0b00000,
    0b10000,
    0b11111
};

//Sad12
const PROGMEM char Sad12[8] = {
    0b00000,
    0b00000,
    0b11000,
    0b00100,
    0b00110,
    0b00000,
    0b00001,
    0b11111
};

//Sad13
const PROGMEM char Sad13[8] = {
    0b00010,
    0b00010,
    0b00010,
    0b00010,
    0b00100,
    0b00100,
    0b11000,
    0b00000
};


//PlayerOne00
const PROGMEM char MafiaOne00[8] = {
    0b01111,
    0b11111,
    0b00111,
    0b00100,
    0b00100,
    0b00100,
    0b00011,
    0b00001
};

//PlayerOne01
const PROGMEM char MafiaOne01[8] = {
    0b11100,
    0b11110,
    0b11000,
    0b01000,
    0b01000,
    0b01000,
    0b10100,
    0b00101
};

//PlayerOne10
const PROGMEM char MafiaOne10[8] = {
    0b00011,
    0b00101,
    0b00001,
    0b00011,
    0b00100,
    0b00100,
    0b11100,
    0b11100
};

//PlayerOne11
const PROGMEM char MafiaOne11[8] = {
    0b10110,
    0b01100,
    0b00111,
    0b10000,
    0b01000,
    0b01000,
    0b01100,
    0b01100
};

//PlayerTwo00
const PROGMEM char MafiaTwo00[8] = {
    0b11111,
    0b01111,
    0b00111,
    0b00100,
    0b00100,
    0b00100,
    0b00011,
    0b00001
};

//PlayerTwo01
const PROGMEM char MafiaTwo01[8] = {
    0b11110,
    0b11100,
    0b11000,
    0b01000,
    0b01000,
    0b01001,
    0b10011,
    0b00111
};

//PlayerTwo10
const PROGMEM char MafiaTwo10[8] = {
    0b00011,
    0b00101,
    0b00001,
    0b00011,
    0b00100,
    0b00100,
    0b00100,
    0b00100
};

//PlayerTwo11
const PROGMEM char MafiaTwo11[8] = {
    0b10111,
    0b01010,
    0b00110,
    0b10010,
    0b01000,
    0b01000,
    0b01000,
    0b01000
};


//TSU00
const PROGMEM char TSU00[8] = {
    0b01100,
    0b00111,
    0b00011,
    0b10000,
    0b11110,
    0b01111,
    0b00010,
    0b00010
};

//TSU01
const PROGMEM char TSU01[8] = {
    0b00000,
    0b11100,
    0b11111,
    0b00011,
    0b00000,
    0b11110,
    0b11111,
    0b00000
};

//TSU02
const PROGMEM char TSU02[8] = {
    0b00000,
    0b00111,
    0b11111,
    0b11000,
    0b00000,
    0b01111,
    0b11111,
    0b00000
};

//TSU03
const PROGMEM char TSU03[8] = {
    0b00100,
    0b11100,
    0b11000,
    0b00010,
    0b11110,
    0b11100,
    0b00000,
    0b00000
};


//TSU10
const PROGMEM char TSU10[8] = {
    0b00110,
    0b00110,
    0b00100,
    0b00010,
    0b00110,
    0b00110,
    0b00011,
    0b00001
};

//TSU11
const PROGMEM char TSU11[8] = {
    0b01111,
    0b10000,
    0b01111,
    0b00111,
    0b00000,
    0b01111,
    0b00000,
    0b11111
};

//TSU12
const PROGMEM char TSU12[8] = {
    0b11111,
    0b00000,
    0b11100,
    0b11110,
    0b00001,
    0b11110,
    0b00000,
    0b11111
};

//TSU13
const PROGMEM char TSU13[8] = {
    0b11100,
    0b00000,
    0b01100,
    0b01100,
    0b01100,
    0b01100,
    0b11000,
    0b10000
};

//War00
const PROGMEM char War00[8] = {
    0b00000,
    0b01000,
    0b01000,
    0b01110,
    0b00111,
    0b00011,
    0b00000,
    0b00000
};

//War01
const PROGMEM char War01[8] = {
    0b00010,
    0b00011,
    0b00001,
    0b00000,
    0b10001,
    0b11011,
    0b11110,
    0b11110
};

//War02
const PROGMEM char War02[8] = {
    0b00000,
    0b00000,
    0b10110,
    0b11111,
    0b00111,
    0b00101,
    0b01101,
    0b00000
};

//War03
const PROGMEM char War03[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b10000,
    0b11000,
    0b11100,
    0b11110
};

//War10
const PROGMEM char War10[8] = {
    0b11000,
    0b00010,
    0b00010,
    0b11000,
    0b00001,
    0b00101,
    0b00100,
    0b00000
};

//War11
const PROGMEM char War11[8] = {
    0b01111,
    0b01101,
    0b00111,
    0b00110,
    0b01100,
    0b00000,
    0b00000,
    0b00000
};

//War12
const PROGMEM char War12[8] = {
    0b00000,
    0b00001,
    0b00001,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000
};

//War13
const PROGMEM char War13[8] = {
    0b11011,
    0b11111,
    0b00011,
    0b00110,
    0b00100,
    0b00000,
    0b00000,
    0b00000
};

enum Characters {
    TITLE_ANIM_1,
    TITLE_ANIM_2,
    KAISHI,
    SLIME_ANIM_1,
    SLIME_ANIM_2,
    SKULL,
    GUN_BIG,
    BUTTONUP,
    BUTTONDOWN,
    DEATH,
    FLAG_ANIM_1,
    FLAG_ANIM_2,
    SAD,
    MAFIAONE,
    MAFIATWO,
    TSU,
    WAR_BEGIN,
};


class GameScreen
{
  public:
  	static GameScreen* getInstance();

  	void Init(LiquidCrystal_I2C* lcd);
  	void Print(String words, uint8_t x, uint8_t y);
    void Draw(uint8_t character, uint8_t x, uint8_t y);
    void Clear();
  	
  protected:
	GameScreen(){}
  private:
  	static GameScreen* s_instance;

	bool _DEBUG;
    LiquidCrystal_I2C*  _lcd;

    void _drawTitleA1(uint8_t x, uint8_t y);
    void _drawTitleA2(uint8_t x, uint8_t y);
    void _drawKaishi(uint8_t x, uint8_t y);
    void _drawSlimeA1(uint8_t x, uint8_t y);
    void _drawSlimeA2(uint8_t x, uint8_t y);
    void _drawSkull(uint8_t x, uint8_t y);
    void _drawGunBig(uint8_t x, uint8_t y);
    void _drawButton(uint8_t x, uint8_t y);
    void _drawButtonDown(uint8_t x, uint8_t y);
    void _drawDeath(uint8_t x, uint8_t y);
    void _drawFlagA1(uint8_t x, uint8_t y);
    void _drawFlagA2(uint8_t x, uint8_t y);
    void _drawSad(uint8_t x, uint8_t y);
    void _drawMafiaOne(uint8_t x, uint8_t y);
    void _drawMafiaTwo(uint8_t x, uint8_t y);
    void _drawTSU(uint8_t x, uint8_t y);
    void _drawWarBegin(uint8_t x, uint8_t y);



};


#endif