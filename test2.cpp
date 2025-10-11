#include <iostream>
#include "Salesman.h"
#include "SalesReport.h"

using namespace std;

int main() {
    SalesReport team1(3);
    team1.computeStats();
    cout << team1.getTeamInfo() << endl;
    cout << team1.getBestClerk().getSalesmanInfo() << endl;

    return 0;
}