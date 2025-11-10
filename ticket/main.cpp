#include <iostream>
using namespace std;

#include "Ticket.h"
#include "GeneralTicket.h"
#include "AdvancedTicket.h"

int main() {
    cout << "202211305 박지원" << endl;
    Ticket ticket(1000.0);
    ticket.show();
    std::cout << "-----------------" << endl;

    AdvancedTicket aticket(1000.0, 20);
    aticket.show();
    std::cout << "-----------------" << endl;

    GeneralTicket gticket(2000.0, true);
    gticket.show();
    std::cout << "------------------" << endl;
}