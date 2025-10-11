#include "SalesReport.h"
#include <string>
using namespace std;

SalesReport::SalesReport(const int number) : NUMBER(number), team(new Salesman[NUMBER]) {
    for (int i = 0; i < NUMBER; i++) {
        team[i].readInput();
    }
}

SalesReport::~SalesReport() {
    if (team != nullptr)
        delete[] team;
    team = nullptr;
}

void SalesReport::computeStats() {
    if (team != nullptr) {
        double sum = team[0].getSales();
        highestSales = sum;
        for (int i = 1; i < NUMBER; i++) {
            if (highestSales < team[i].getSales())
                highestSales = team[i].getSales();
            sum += team[i].getSales();
        }
        averageSales = sum / NUMBER;
    }
}

Salesman& SalesReport::getBestClerk() {
    int bestIdx = 0;
    for (int i = 1; i < NUMBER; i++) {
        if (team[bestIdx].getSales() < team[i].getSales())
            bestIdx = i;
    }
    return team[bestIdx];
}

string SalesReport::getTeamInfo() {
    string info = "인원 수: " + to_string(NUMBER) + "\n";
    info += "평균 판매량: " + to_string(averageSales) + "\n";
    info += "최고 판매량: " + to_string(highestSales) + "\n";
    return info;
}