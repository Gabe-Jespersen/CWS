//endcheck.cpp

#include <iostream>

#include "endcheck.h"

using namespace std;

void checkEnd(short happiness, short techDiscovered, unsigned long population, unsigned long landArea)
{
    if(happiness < 1)
    {
        lose(0);
    }
    if(population < 2) //can't have kids with 1 person
    {
        lose(1);
    }
    if(landArea < 1)
    {
        lose(2);
    }
    if(techDiscovered > 100)
    {
        win(0);
    }
}

void lose(unsigned short ending)
{
    if(ending == 0)
    {
        cout << "You have lost, your people hated you as a ruler, and rioted\n";
    }
    if(ending == 1)
    {
        cout << "Your people have died, one way or another, your empire is over\n";
    }
    if(ending == 2)
    {
        cout << "Your people's land has been taken, you have lost\n";
    }
    exit(0);
}

void win (unsigned short ending)
{
    if(ending == 0)
    {
        cout << "You have discovered all technology, your citizens can live forever, and get anything they want at a moments notice\n";
    }
    cout << "Good job, you win\n";
    exit(0);
}
