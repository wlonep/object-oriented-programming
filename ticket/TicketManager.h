#pragma once
#include <string>

#include "Ticket.h"
using std::string;

class TicketManager {
protected:
    string m_name;
    int totalNumber;
    Ticket** ticket = nullptr;
    int count = 0;
public:
    TicketManager()=delete;
    ~TicketManager();
    TicketManager(const string& name, int number);
    void buy(Ticket* newTicket);
    void show() const;
    void showGeneralTicket(const bool& card) const;
    void showAdvancedTicket() const;
};

std::ostream& operator<<(std::ostream& out, const TicketManager& manager);

