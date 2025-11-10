#include <iostream>

#include "TicketManager.h"
using namespace std;

#include "Ticket.h"
#include "GeneralTicket.h"
#include "AdvancedTicket.h"
#include "TicketManager.h"

int main() {
    cout << "202211305 박지원" << endl;
    /*Ticket ticket(1000.0);
    ticket.show();
    std::cout << "-----------------" << endl;

    AdvancedTicket aticket(1000.0, 20);
    aticket.show();
    std::cout << "-----------------" << endl;

    GeneralTicket gticket(2000.0, true);
    gticket.show();
    std::cout << "------------------" << endl;*/

    TicketManager manager("아이유콘서트", 10);
    manager.buy(new AdvancedTicket(1000, 40));
    manager.buy(new AdvancedTicket(1500, 30));
    manager.buy(new AdvancedTicket(2000, 25));
    manager.buy(new AdvancedTicket(1000, 5));
    manager.buy(new GeneralTicket(2000, true));
    manager.buy(new GeneralTicket(1500, false));

    cout << manager << endl;

    manager.showGeneralTicket(true);
    manager.showGeneralTicket(false);
    manager.showAdvancedTicket();
    return 0;
}