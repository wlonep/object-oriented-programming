#include "TicketManager.h"

#include <iostream>

#include "AdvancedTicket.h"
#include "GeneralTicket.h"
using namespace std;

TicketManager::TicketManager(const string& name, int number): m_name(name), totalNumber(number) {
    ticket = new Ticket *[totalNumber];
    for (int i = 0; i < totalNumber; i++) {
        ticket[i] = nullptr;
    }
}

TicketManager::~TicketManager() {
    for (int i = 0; i < count; i++) {
        delete ticket[i];
        ticket[i] = nullptr;
    }
    delete[] ticket;
    ticket = nullptr;
}

void TicketManager::buy(Ticket *newTicket) {
    if (count >= totalNumber) {
        cout << "더 이상 티켓을 구매할 수 없습니다." << endl;
        return;
    }

    ticket[count++] = newTicket;
}

void TicketManager::show() const {
    cout << "----- 티켓 예약 현황 -----" << endl;
    cout << "총 예약 매수: " << count << endl;
    cout << "---------------" << endl;
    double total = 0;
    for (int i = 0; i < count; i++) {
        if (const auto* a = dynamic_cast<AdvancedTicket*>(ticket[i])) {
            a->show();
            total += a->getPrice();
        } else if (const auto* g = dynamic_cast<GeneralTicket*>(ticket[i])) {
            g->show();
            total += g->getPrice();
        }
        cout << endl;
    }
    cout << "---------------" << endl;
    cout << "총 예약 금액: " << total << endl;
    cout << "---------------" << endl;
}

void TicketManager::showGeneralTicket(const bool &card) const {
    cout << "----- 일반 예약 현황 -----" << endl;
    cout << "카드 결제 여부: " << boolalpha << card << endl;
    cout << "---------------" << endl;

    double total = 0;
    for (int i = 0; i < count; i++) {
        if (auto* g = dynamic_cast<GeneralTicket*>(ticket[i])) {
            if (g->getPayByCredit() == card) {
                g->show();
                total += g->getPrice();
                cout << endl;
            }
        }
    }
    cout << "---------------" << endl;
    cout << "총 예약 금액: " << total << endl;
    cout << "---------------" << endl;
}

void TicketManager::showAdvancedTicket() const {
    cout << "----- 사전 예약 현황 -----" << endl;
    double total = 0;
    for (int i = 0; i < count; i++) {
        if (auto* g = dynamic_cast<AdvancedTicket*>(ticket[i])) {
            g->show();
            total += g->getPrice();
            cout << endl;
        }
    }
    cout << "---------------" << endl;
    cout << "총 예약 금액: " << total << endl;
    cout << "---------------" << endl;
}

ostream& operator<<(ostream& out, const TicketManager& manager) {
    manager.show();
    return out;
}
