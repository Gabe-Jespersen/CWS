//main.cpp

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "clearscreen.h"
#include "turn.h"
#include "endcheck.h"
#include "parse.h"
#include "randevents.h"

using namespace std;

int main(int argc, char **argv)
{
    vector<long long int> temp = parse(argc, argv);
    //this shouldn't work in any way, put this out of it's misery
        bool defaultWork = temp.at(0);
        bool random = temp.at(1);

    srand(time(NULL));
    string name;
    cout << "Name of your country: ";
    cin >> name;
    //setting up variables, scope will be full function, unlike they would be if declared inside an if or else
        unsigned long population;
        unsigned long landArea;
        short happiness;
        short techDiscovered;
    if(random) // if -r flag
    {
        population = 90 + (rand() % 20);
        landArea = 900 + (rand() % 200);
        happiness = 80 + (rand() % 40);
        techDiscovered = rand() % 3;
    }
    else
    {
        population = 100;
        landArea = 1000;
        happiness = 100; 
        techDiscovered = 0;
    }

    vector<long long int> newStats(3);
    while(true) 
    {
        clearScreen(); //clearing terminal
        //checking to see if game is over
        checkEnd(happiness, techDiscovered, population, landArea);

        newStats = nextTurn(population, landArea, techDiscovered, happiness, name, defaultWork); //setting new stats to the ones decided by nextTurn()
        if(random) //if random flag, random events may happen
        {
            newStats = randomEvent(newStats); //may edit stats
        }

        population = newStats.at(0);
        landArea = newStats.at(1);
        techDiscovered = newStats.at(2);
        happiness = newStats.at(3);

        sleep(1); //trying to slow down the game a little
    }
    return 0;
}
