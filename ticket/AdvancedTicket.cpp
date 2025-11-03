#include "AdvancedTicket.h"
#include <iostream>
using namespace std;

AdvancedTicket::AdvancedTicket(double price, int advanceDays) : Ticket(price), advanceDays(advanceDays) {
}

AdvancedTicket::~AdvancedTicket() {
}

double AdvancedTicket::getPrice() const {
    double discount = 0.0;
    if (advanceDays >= 30) discount = 0.5;
    else if (advanceDays >= 20) discount = 0.3;
    else if (advanceDays >= 10) discount = 0.1;
    return price * (1 - discount);
}

int AdvancedTicket::getAdvanceDays() const {
    return advanceDays;
}

void AdvancedTicket::show() const {
    cout << "티켓 번호: " << number << endl;
    cout << "가격 정보: " << price << endl;
    cout << "사전 예약일: " << advanceDays << endl;
    cout << "지불 금액: " << getPrice() << endl;
}
