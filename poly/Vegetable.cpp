#include <iostream>
#include "Vegetable.h"
using namespace std;

Vegetable::Vegetable(const string &name, const int &price,
                     const string &origin, const int &weight): Product(name, price), m_origin(origin), m_weight(weight) {

}

Vegetable::~Vegetable() {}

int Vegetable::getPrice() const {
    return m_price;
}

void Vegetable::show() const {
    cout << "[채소] " << m_name << endl;
    cout << "- 원산지: " << m_origin << endl;
    cout << "- 무게: " << m_weight << endl;
    cout << "- 가격: " << m_price << endl;
}