#include <iostream>
#include <ctime>
#include "Dice.h"
#include "Player.h"

using namespace std;

int main() {
    srand((unsigned) time(NULL));

    Dice dice1, dice2;
    Player player1, player2;
    player1.setName("홍길동");
    player2.setName("김길동");
    player1.roll(dice1, dice2);
    player2.roll(dice1, dice2);

    if (player1.getTotal() > player2.getTotal())
        cout << player1.getName() << " 승리" << endl;
    else if (player1.getTotal() == player2.getTotal())
        cout << "무승부" << endl;
    else
        cout << player2.getName() << " 승리" << endl;
    return 0;
}