#include "Ticket.h"
#include <iostream>
using namespace std;

Ticket::Ticket(double price) {
    static int count = 0;
    this->number = ++count;
    this->price = price;
}

Ticket::~Ticket() {
}

int Ticket::getNumber() const {
    return number;
}

double Ticket::getPrice() const {
    return price;
}

void Ticket::setPrice(const double &price) {
    this->price = price;
}

void Ticket::show() const {
    cout << "티켓 번호: " << number << endl;
    cout << "가격 정보: " << price << endl;
}
