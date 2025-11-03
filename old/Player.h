#pragma once
#include <string>
#include "Dice.h"

using std::string;

class Player {
private:
    string m_name;
    int m_total;
public:
    void setName(const string &name);
    string getName();
    void roll(Dice& dice1, Dice& dice2);
    int getTotal();
};
