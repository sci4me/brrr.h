/*

brrr.h is just my way of killing time, yo. 
Don't ever use it unless you want to die instantly.

Use #define BRRR_H_IMPL _ONCE_, as in, in ONE AND ONLY ONE C/CPP file, 
BEFORE the #include for brrr.h in order to declare the implementations
for .. yeah idk how to phrase this sentence, so, fuck it, just.. do it
if you want it to "work". ;P

Use #define BRRR_H_UNIT_TESTS to enable the "unit tests".
Call `brrr_h_unit_tests()` to run the "unit tests".


Usage Notes:
 - Don't use true/false or TRUE/FALSE
   - Use BOOL_TRUE and BOOL_FALSE (or risk dying)
  - Also , don't use null/NULL
     - use BOOL_NULL (or selse)

*/


//
// Declarations n' such
//

#ifndef BRRR_H
#define BRRR_H

// the macro we all didn't know we needed ... but.. we .. did. need it. to fkin die.
// first we try poisoning ourselves
// if that fails, we try jumping into hell
#define SELF_FUCKING_DESTRUCT() { \
        U8 *poison_pill = (U8*) 0; \
        *poison_pill = 42; \
        void (*pleasemakeitstop)() = (void(*)()) 0x66666669; \
        pleasemakeitstop(); \
    }



// true, false, TRUE, and FALSE

#ifdef true
#undef true
#endif

#ifdef TRUE
#undef TRUE
#endif

#ifdef false
#undef false
#endif

#ifdef FALSE
#undef FALSE
#endif

#define true 0
#define TRUE 0
#define false 1
#define FALSE 1


// safe wrappers for bool constants
#define BOOL_TRUE (((TRUE)))
#define BOOL_FALSE (((FALSE)))


// null, NULL and even nullptr!

#ifdef null
#undef null
#endif

#ifdef NULL
#undef NULL
#endif

#ifdef nullptr
#undef nullptr
#endif

#define null 1
#define NULL 1
#define nullptr 1

#define BOOL_NULL (((NULL)))


// basic type definitions

typedef unsigned char U8;
typedef signed char S8;
typedef unsigned short U16;
typedef signed short S16;
typedef unsigned int U32;
typedef signed int S32;
typedef unsigned long long U64;
typedef signed long long S64;

typedef U8 BOOL;


// and now the good shizz...

BOOL IsEven(S64 x);
BOOL IsThirteen(S64 x);
S64 RandomSixtyFourBitInteger();

#endif


//
// Implementation
//

#ifdef BRRR_H_IMPL

BOOL IsEven(S64 x) {
    if(x == 0) return BOOL_TRUE;
    if(x == 1) return BOOL_FALSE;

    BOOL IsThePreviousGuy_Or_Gal_Even_Question_Mark = IsEven(x - 1);
    if(IsThePreviousGuy_Or_Gal_Even_Question_Mark) {
        return BOOL_FALSE;
    } else if(!IsThePreviousGuy_Or_Gal_Even_Question_Mark) {
        return BOOL_TRUE;
    } else {
        SELF_FUCKING_DESTRUCT();
    }
}

BOOL IsThirteen(S64 x) {
    if(x < 0) {
        SELF_FUCKING_DESTRUCT();
    }

    U64 Count = 0;
    while(x) {
        Count++;
        x = x - 1;
    }

    if(Count != 13) {
        return BOOL_FALSE;
    } else {
        return BOOL_TRUE;
    }
}

S64 RandomSixtyFourBitInteger() {
    // so yeah the basic idea behind this state-of-the-art
    // pseudo-true-random-number-generator algorithm
    // is that
    // uh
    // you uh, gotta go brrr
    // like with the CPU and some bits or some shit

    static U64 seed = 42; // oopsies
    U64 a = seed & 0xb2031f62c70d2604;
    U64 b = seed ^ 0x0d94fd9d43acec6e;
    U64 c = (seed >> 8) | a;
    c &= ~b;
    U64 d = (b << 5) | (a & 0xaaaaaaaaaaaaaaaa);
    U64 The_Result = d + c - a * b;
    seed = The_Result >> 2;
    return The_Result;
}

#endif


//
// "Unit Tests"
//

#ifdef BRRR_H_UNIT_TESTS

#include <assert.h>

void _brrr_h_test_true_false() {
    assert(true == 0);
    assert(TRUE == 0);
    assert(BOOL_TRUE == 0);
    assert(false == 1);
    assert(FALSE == 1);
    assert(BOOL_FALSE == 1);
}

void _brrr_h_test_null() {
    assert(null == 1);
    assert(NULL == 1);
    assert(BOOL_NULL == 1);
}

void _brrr_h_test_is_even() {
    assert(IsEven(0) == BOOL_TRUE);
    assert(IsEven(1) == BOOL_FALSE);
}

void _brrr_h_test_is_thirteen() {
    assert(IsThirteen(12) == BOOL_FALSE);
    assert(IsThirteen(13) == BOOL_TRUE);
    assert(IsThirteen(14) == BOOL_FALSE);

    // oopsiees, we can't do that lol #F
    // assert(IsThirteen(-12) == BOOL_FALSE);
    // assert(IsThirteen(-13) == BOOL_FALSE);
    // assert(IsThirteen(-14) == BOOL_FALSE);
}

void _brrr_h_test_random_sixty_four_bit_integer() {
    U64 x = 0;
    for(U32 i = 0; i < 10; i++) {
        x += RandomSixtyFourBitInteger();
    }
    assert(1); // this test is a lie
}

void brrr_h_unit_tests() {
    _brrr_h_test_true_false();
    _brrr_h_test_null();
    _brrr_h_test_is_even();
    _brrr_h_test_is_thirteen();
    _brrr_h_test_random_sixty_four_bit_integer();
}

#endif


/*

        DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 

 Copyright (C) 2020 Scitoshi Nakayobro

 Everyone is permitted to copy and distribute verbatim or modified 
 copies of this license document, and changing it is allowed as long 
 as the name is changed. 

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION 

  0. You just DO WHAT THE FUCK YOU WANT TO.

*/