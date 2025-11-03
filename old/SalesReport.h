#pragma once

#include "Salesman.h"

class SalesReport {
private:
    const int NUMBER;
    Salesman* team;
    double highestSales;
    double averageSales;
public:
    SalesReport(const int number);
    ~SalesReport();
    void computeStats();
    Salesman& getBestClerk();
    string getTeamInfo();
};
