// randevents.cpp

#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<long long int> randomEvent(vector<long long int> stats) 
{
    //reading stats from vector the was returned by nextTurn()
    unsigned long population = stats.at(0);
    unsigned long landArea = stats.at(1);
    short techDiscovered = stats.at(2);
    short happiness = stats.at(3);

    srand(time(NULL));
    char eventChoice = rand()%100; //random chance of events

         if(eventChoice == 0 && happiness < 50)
    {
        cout << "People leave your village due to being unhappy, lay off the work\n";
        population *= 0.75;
    }
    else if(eventChoice == 1)
    {
        cout << "Animals ransack your village and people go hungry\n";
        population *= 0.9;
    }
    else if(eventChoice == 2 && happiness > 100)
    {
        cout << "Your people are happy, they invite others in and your population goes up\n";
        population *= 1.1;
    }
    else if(eventChoice == 3)
    {
        cout << "There is a fire, you lose land\n";
        landArea *= 0.8;
    }
    else if(eventChoice == 4)
    {
        cout << "By luck you discover a new technology\n";
        techDiscovered += 1;
    }
    vector <long long int> toreturn = {population, landArea, techDiscovered, happiness};
    return toreturn;
}
