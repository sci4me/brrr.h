/*

brrr.h is just my way of killing time, yo. 
Don't ever use it unless you want to die instantly.

Use #define BRRR_H_IMPL _ONCE_, as in, in ONE AND ONLY ONE C/CPP file, 
BEFORE the #include for brrr.h in order to declare the implementations
for .. yeah idk how to phrase this sentence, so, fuck it, just.. do it
if you want it to "work". ;P

Use #define BRRR_H_UNIT_TESTS to enable the "unit tests".
Call `brrr_h_unit_tests()` to run the "unit tests".

*/


//
// Declarations n' such
//

#ifndef BRRR_H
#define BRRR_H


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

#endif


//
// Implementation
//

#ifdef BRRR_H_IMPL

BOOL IsEven(S64 x) {
    if(x == 0) return TRUE;
    if(x == 1) return FALSE;
    return !IsEven(x - 1);
}

BOOL IsThirteen(S64 x) {
    if(x < 0) {
        U8 *poison_pill = (U8*) 0;
        *poison_pill = 42;
    }

    U64 Count = 0;
    while(x) {
        Count++;
        x = x - 1;
    }

    if(Count != 13) {
        return FALSE;
    } else {
        return TRUE;
    }
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
    assert(false == 1);
    assert(FALSE == 1);
}

void _brrr_h_test_null() {
    assert(null == 1);
    assert(NULL == 1);
}

void _brrr_h_test_is_even() {
    assert(IsEven(0) == TRUE);
    assert(IsEven(1) == FALSE);
}

void _brrr_h_test_is_thirteen() {
    assert(IsThirteen(12) == FALSE);
    assert(IsThirteen(13) == TRUE);
    assert(IsThirteen(14) == FALSE);

    // oopsiees, we can't do that lol #F
    // assert(IsThirteen(-12) == FALSE);
    // assert(IsThirteen(-13) == FALSE);
    // assert(IsThirteen(-14) == FALSE);
}

void brrr_h_unit_tests() {
    _brrr_h_test_true_false();
    _brrr_h_test_null();
    _brrr_h_test_is_even();
    _brrr_h_test_is_thirteen();
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