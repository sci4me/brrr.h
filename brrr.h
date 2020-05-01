/*

brrr.h is just my way of killing time, yo. 
Don't ever use it unless you want to die instantly.

Use #define BRRR_H_UNIT_TESTS to enable the "unit tests".
Call `brrr_h_unit_tests()` to run the "unit tests".

*/


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


#endif


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

void brrr_h_unit_tests() {
    _brrr_h_test_true_false();
    _brrr_h_test_null();
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