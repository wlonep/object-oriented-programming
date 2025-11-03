#include <iostream>
#include "Salesman.h"
using namespace std;

void show(const Salesman& s) {
    //cout << s.getName() << endl;
    cout << s.m_name << endl;
}

Salesman getSalesman(const string& name) {
    Salesman s(name);
    return s;
}
Salesman getSalesman2(const string& name) {
    return Salesman(name);
}
int main() {
    cout << "202211305 박지원" << endl;
    Salesman s1;
    Salesman s2("greenjoa");
    Salesman s3("greenjoa",200.0);

    Salesman copy1(s2);
    Salesman copy2 = s3;
    cout << copy1.getSalesmanInfo() << endl;
    cout << copy2.getSalesmanInfo() << endl;
    Salesman copy3 = Salesman("greenjoa");

    cout << "=================" << endl;
    copy3.showFriend(s3);
    cout << "=================" << endl;
    Salesman s4 = getSalesman("greenjoa4");
    cout << "=================" << endl;
    Salesman s5 = getSalesman2("greenjoa4");
    //Salesman s4 = "greenjoa"s;
    /*auto str = "greenjoa";
    cout << typeid(str).name() << endl;
    auto str2 = "greenjoa"s;
    cout << typeid(str2).name() << endl;

    cout << s3.getSalesmanInfo() << endl;*/
    //show(s1);
}