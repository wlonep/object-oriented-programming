#include "GeneralTicket.h"
#include <iostream>
using namespace std;

GeneralTicket::GeneralTicket(double price, bool payByCredit) : Ticket(price), payByCredit(payByCredit) {
}

GeneralTicket::~GeneralTicket() {
}

bool GeneralTicket::getPayByCredit() const {
    return payByCredit;
}

double GeneralTicket::getPrice() const {
    if (payByCredit)
        return price * 1.1;
    return price;
}

void GeneralTicket::show() const {
    cout << "티켓 번호: " << number << endl;
    cout << "가격 정보: " << price << endl;
    cout << "카드 결제 여부: " << payByCredit << endl;
    cout << "지불 금액: " << getPrice() << endl;
}
