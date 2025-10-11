#include "Player.h"
#include <iostream>
using namespace std;


void Player::setName(const string &name) {
    m_name = name;
}

string Player::getName() {
    return m_name;
}

void Player::roll(Dice& dice1, Dice& dice2) {
    cout << m_name << " 주사위 던짐" << endl;
    dice1.roll();
    dice2.roll();
    m_total = dice1.getFaceValue() + dice2.getFaceValue();
}

int Player::getTotal() {
    return m_total;
}