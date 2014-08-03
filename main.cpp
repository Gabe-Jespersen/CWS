//main.cpp

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "clearscreen.h"
#include "turn.h"
#include "endcheck.h"
#include "parse.h"

using namespace std;

int main(int argc, char **argv)
{
    vector<int> temp = parse(argc, argv);
    //this shouldn't work in any way, put this out of it's misery
        bool defaultWork = temp.at(0);

    srand(time(NULL));
    string name;
    cout << "Name of your country: ";
    cin >> name;
    unsigned long int population = 100;
    unsigned long int landArea = 1000;
    short happiness = 100; //only used for loss if 0, decreases when a Census is ran, increases if labor is light
    int techDiscovered = rand() % 3; //giving a little randomness in beginning, maybe should do this with population and land

    vector<int> newStats(3);
    while(true) //needs to be changed to check for win
    {
        clearScreen(); //clearing terminal
        newStats = nextTurn(population, landArea, techDiscovered, happiness, name, defaultWork); //setting new stats to the ones decided by nextTurn()
        population = newStats.at(0);
        landArea = newStats.at(1);
        techDiscovered = newStats.at(2);
        happiness = newStats.at(3);
        sleep(1);

        //sleep(1); //trying to slow down the game a little
        checkEnd(happiness, techDiscovered, population, landArea);
    }
    return 0;
}
