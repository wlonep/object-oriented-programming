#include <iostream>
#include "TV.h"
using namespace std;

TV::TV(const string &name, const int &price, const int &size) : Product(name, price), m_size(size) {

}

TV::~TV() {

}

int TV::getPrice() const {
    return m_price;
}

void TV::show() const {
    cout << "[TV] " << m_name << endl;
    cout << "- 크기: " << m_size << endl;
    cout << "- 가격: " << m_price << endl;
}