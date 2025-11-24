#include <iostream>
#include <list>
#include <vector>
#include "ArrayData/CMyPoint.h"
#include "template/Student.h"

using namespace std;

template<typename T>
void printArr(list<T> &v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

list<string> getStudent(list<list<string> > &std, list<string> &droplist) {
    droplist.unique();
    list<string> result;
    for (auto &s: std) {
        result.splice(result.end(), s);
    }

    for (auto &d: droplist) {
        result.remove(d);
    }
    result.sort();
    result.unique();
    return result;
}

int main() {
    cout << "202211305 박지원" << endl;
    /*vector<int> intVec;
    for (int i = 0; i < 10; ++i) {
        intVec.push_back(i);
        cout << intVec.size() << ", " << intVec.capacity() << endl;
    }*/

    /*vector<int> arr1({1,2,3,4,5});
    vector<double> arr2;
    arr2.push_back(10.5);
    arr2.push_back(10.5);
    arr2.push_back(10.5);
    arr2.insert(arr2.begin(), 14.6);
    printArr(arr1);
    printArr(arr2);*/

    /*vector<CMyPoint> points;
    for (int i = 0; i < 5; ++i) {
        points.push_back(CMyPoint(i * 10, i * 10));
    }
    printArr(points);*/

    /*list<int> list1({1,2,3,3,3,4,5});
    list1.unique();
    printArr(list1);*/

    /*list<CMyPoint> list2;
    list2.push_back(CMyPoint(10, 10));
    list2.emplace_back(20, 20);
    list2.emplace_back(30, 30);
    list2.emplace_back(40, 40);
    list2.push_front(CMyPoint(10, 10));
    list2.unique();
    // printArr(list2);

    list<CMyPoint> list3;
    list3.push_back(CMyPoint(10, 10));
    list3.push_back(CMyPoint(50, 50));
    list2.splice(list2.end(), list3);
    cout << list3.size() << endl;
    printArr(list2);*/

    list<list<string> > std;
    std.push_back({"greenjoa1", "bluejoa1", "greenjoa3"});
    std.push_back({"greenjoa1", "greenjoa3"});
    std.push_back({"redjoa1", "greenjoa2", "bluejoa2"});
    list<string> droplist({"greenjoa2", "bluejoa1"});

    auto student = getStudent(std, droplist);
    printArr(student);
    return 0;
}
