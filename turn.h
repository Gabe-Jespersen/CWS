//turn.h

#include <vector>
#include <string>

#ifndef TURN_H
#define TURN_H

std::vector<long long int> nextTurn(unsigned long population, unsigned long landArea, short techDiscovered, short happiness, std::string name, bool defaultWork);
std::vector<double> findMultiplier(short techDiscovered);

#endif
