//turn.h

#include <vector>
#include <string>

#ifndef TURN_H
#define TURN_H

std::vector<int> nextTurn(unsigned long population, unsigned long landArea, int techDiscovered, short happiness, std::string name, bool defaultWork);
std::vector<double> findMultiplier(int techDiscovered);

#endif
