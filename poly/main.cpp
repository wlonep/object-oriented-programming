#include <iostream>
#include "Customer.h"
#include "TV.h"
#include "Vegetable.h"
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

int main() {
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    Customer c1("홍길동", 1);
    c1.buy(new TV("OLED", 100000, 25));
    c1.buy(new Vegetable("사과", 1000, "강원도", 10));
    c1.showlist();
    cout << "---------------" << endl;
    /*Customer c2("고길동", 2);
    c2.buy(t1);
    c2.showlist();*/
}