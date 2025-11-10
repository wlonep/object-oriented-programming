#include <iostream>
#include "Customer.h"
#include "TV.h"
#include "Vegetable.h"

using namespace std;

Customer::Customer(const string &name, const int &number) : m_name(name), m_number(number) {
    for (int i = 0; i < 100; i++)
        products[i] = nullptr;
}

Customer::~Customer() {
    for (int i = 0; i < m_count; i++) {
        delete products[i];
    }
}

void Customer::buy(Product* product) {
    products[m_count++] = product;
}

string Customer::getName() const {
    return m_name;
}

int Customer::getCount() const {
    return m_count;
}

void Customer::showlist() const {
    cout << "고객 이름: " << m_name << endl;
    /*cout << "고객 번호: " << m_number << endl;
    cout << "구매 목록: " << endl;
    for (int i = 0; i < m_count; i++) {
        products[i]->show();
    }*/
    cout << "구매 개수: " << m_count << endl;
    double price = 0;
    for (int i = 0; i < m_count; i++) {
        price += products[i]->getPrice();
    }
    cout << "총 구매 가격: " << price << endl;
}


void Customer::showTVList() const {
    for (int i = 0; i < m_count; i++) {
        auto* derived = dynamic_cast<TV*>(products[i]);
        if (derived) products[i]->show();
    }
}
void Customer::showVegetableList() const {
    for (int i = 0; i < m_count; i++) {
        auto* derived = dynamic_cast<Vegetable*>(products[i]);
        if (derived) products[i]->show();
    }
}