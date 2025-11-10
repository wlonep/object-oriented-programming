#pragma once
#include "Product.h"
#include <iostream>
using std::string;

class Customer {
private:
    string m_name;
    int m_number;
    int m_count = 0;
    Product* products[100];
public:
    Customer(const string &name, const int &number);

    ~Customer();

    void buy(Product* product);

    string getName() const;

    int getCount() const;

    void showlist() const;
    void showTVList() const;
    void showVegetableList() const;
};