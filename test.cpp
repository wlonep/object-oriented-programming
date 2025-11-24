#include <iostream>
#include <vector>
#include "ArrayData/CMyPoint.h"

using namespace std;

template<typename T>
void printArr(vector<T>& v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }
}

int main() {
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

    vector<CMyPoint> points;
    for (int i = 0; i < 5; ++i) {
        points.push_back(CMyPoint(i * 10, i * 10));
    }
    printArr(points);
    return 0;
}