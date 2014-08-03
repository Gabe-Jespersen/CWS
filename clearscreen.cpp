// clearscreen.cpp

#include "clearscreen.h"
#include <unistd.h>
#include <term.h>

void clearScreen()
{
    if (!cur_term)
    {
        int result;
        setupterm( NULL, STDOUT_FILENO, &result );
        if(result <= 0)
        {
            return;
        }
    }
    putp(tigetstr("clear") );
    //Uses curses to clear terminal, copied from http://www.cplusplus.com/articles/4z18T05o/, I think it is Unix only, sorry Wangblows
}
