# brrr.h

Lovingly known as bŔřŘ.H, **brrr.h** is essentially the one true solution to every problem that ever existed in the history of ever. It's the code God was built upon.

Please feel free to leave suggestions in the GitHub issues! :)

## What, How, and Why?

So I made this Facebook post right? And like, he was like, yo. Make a library. Of terrible headers.  
And I was drunk enough to get into it.

## But How, for realsies

Okay, here... check this:
```c
#define BRRR_H_IMPL
#include "brrr.h"

#include <stdio.h>

S32 main(S32 argc, char **argv) {
    printf("%d\n", IsEven(42));
    printf("%d\n", IsThirteen(13));
    // ...
    return 0;
}
```

If you include `brrr.h` multiple times, be sure that you don't define `BRRR_H_IMPL` multiple times as well; it only need be defined once.

## License

**brrr.h** is licensed under [WTFPL](http://www.wtfpl.net/).