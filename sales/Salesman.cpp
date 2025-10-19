#include "Salesman.h"
#include <iostream>
using namespace std;

Salesman::Salesman() : Salesman("noName", 0.0) {}
Salesman::Salesman(const Salesman& man) : Salesman(man.m_name, man.m_sales)
{
    cout << "복사 생성자" << endl;
}
Salesman::Salesman(const char* name) : Salesman(name,0.0)
{
}
Salesman::Salesman(const string& name) : Salesman(name, 0.0)
{
}
Salesman::Salesman(const string& name, const double& sales) : m_name(name), m_sales(sales) { count++; }
Salesman::~Salesman(){
    count--;
    //cout << m_name << " 소멸됨" << endl;
}
void Salesman::setName(string& name){
    m_name = name;
}
//string Salesman::getName(){
//	return m_name;
//}
void Salesman::setSales(const double& sales){
    m_sales = sales;
}
double Salesman::getSales(){
    return m_sales;
}
void Salesman::readInput(){
    cout << "이름 : ";
    cin >> m_name;
    cout << "실적 : ";
    cin >> m_sales;
}
string Salesman::getSalesmanInfo(){
    return "이름 : " + m_name + " 판매실적 : " + to_string(m_sales);
}

void Salesman::showFriend(Salesman s)
{
    cout << s.getSalesmanInfo() << endl;
}
