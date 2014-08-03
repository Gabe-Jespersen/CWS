//turn.cpp

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <math.h>

#include "turn.h"

using namespace std;


vector<int> nextTurn(unsigned long population, unsigned long landArea, int techDiscovered, short happiness, string name, bool defaultWork)
{
    srand(time(NULL)); //uses a little randomness
    double populationMultiplier = 1.05;
    double landMultiplier = 1;
    double scienceMultiplier = 1.05;
    vector<double> temp = findMultiplier(techDiscovered); //gives base multipliers based on tech discovered
    //multiplying tech advances multipliers and base multipliers
        populationMultiplier *= temp.at(0);
        landMultiplier *= temp.at(1);
        scienceMultiplier *= temp.at(2);

    cout << "1. Research\n" <<
            "2. Explore\n" <<
            "3. Farm\n" <<
            "4. Perform Census\n" <<
            "5. Quit\n";
    char turnChoice;
    cout << "What would you like to do this turn? ";
    cin >> turnChoice;
    if(turnChoice == '1')
    {
        scienceMultiplier *= 1.2;
    }
    else if(turnChoice == '2')
    {
        landMultiplier *= 1.1;
    }
    else if(turnChoice == '3')
    {
        populationMultiplier *= 1.15;
    }
    else if(turnChoice == '4')
    {
        cout << "Census has been completed for " << name << endl;
        cout << "Population is: " << population << endl
             << "Total land owned is: " << landArea << endl
             << "Technologies discovered: " << techDiscovered << endl
             << "Happiness prior to censes: " << happiness << endl << endl;
        cout << "Press enter to continue\n";
        char temp;
        cin.ignore();
        cin.get(temp);
        happiness -= 5; //idk, trying to use happiness, people don't like being asked personal stuff every other day
    }
    else if(turnChoice == '5')
    {
        exit(0);
    }
    else
    {
        cout << "Choice invalid\n";
    }


    //checking if player chose to have work default to 3
    if(!defaultWork)
    {
        char effortChoice;
        cout << "1. Don't work\n" <<
                "2. Lightly work\n" <<
                "3. Moderately work (default)\n" <<
                "4. Aggressively work\n" <<
                "5. Slave labor\n" << endl;
        cout << "How hard would you like your citizens to work? ";
        cin.ignore();
        cin.get(effortChoice);

        if(effortChoice == '1')
        {
            scienceMultiplier = 0;
            landMultiplier = 0;
            populationMultiplier = 0;
            happiness += 5;
        }
        else if(effortChoice == '2')
        {
            scienceMultiplier *= 0.5;
            landMultiplier *= 0.5;
            populationMultiplier *= 0.5;
            happiness += 2;
        }
        //3 is default, after 5, used as an else of all
        else if(effortChoice == '4')
        {
            scienceMultiplier *= 1.5;
            landMultiplier *= 1.5;
            populationMultiplier *= 1.5;
            happiness -= 5;
        }
        else if(effortChoice == '5')
        {
            scienceMultiplier *= 2.5;
            landMultiplier *= 2.5;
            populationMultiplier *= 2.5;
            happiness -= 10;
        }
        else //default
        {
            happiness += 1;
        }
    }
    else
    {
        happiness += 1;
    }
    //add bonuses for population/land
    int populationBonus = (fmin(population, landArea)/1000); //
    for(int i = 1; i < populationBonus; i++)
    {
        scienceMultiplier *= 1.1;
    }


    //decide if tech is discovered
    int tempInt = rand()%100; //percentage chance of discovering new tech is equal to science multiplier
    if(tempInt < scienceMultiplier)
    {
       techDiscovered++; //discover new tech
    }
    vector<int> toreturn = {population*populationMultiplier,landArea*landMultiplier,techDiscovered,happiness}; //looks like shit, works
    return toreturn;
}

vector<double> findMultiplier(int techDiscovered)
{
    double populationMultiplier = 1;
    double landMultiplier = 1;
    double scienceMultiplier = 1;
    int temp = 0;
    for(int i = 0; i < techDiscovered; i++) //by 0,1,2, base tech is increased
    {
        if(temp == 0)
        {
            populationMultiplier *= 1.025;
        }
        if(temp == 1)
        {
            landMultiplier *= 1.01;
        }
        if(temp == 2)
        {
            scienceMultiplier *= 1.1;
        }
        temp = (temp + 1) % 3;
    }
    vector<double> toreturn = {populationMultiplier, landMultiplier, scienceMultiplier}; //returns multiplier from tech
    return toreturn;
}
