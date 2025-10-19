#include <iostream>
#include "ArrayData.h"
#include <vector>
using namespace std;
void showArr(ArrayData& arr1) {
    cout << __FUNCTION__ << "(&)" << endl;
    arr1.showData();
}

void showArr(ArrayData&& arr1) {
    cout << __FUNCTION__ << "(&&)" << endl;
    arr1.showData();
}

ArrayData getArr(const int& num) {
    ArrayData arr(num);
    return arr;
    //return ArrayData(num);
}

void showArray(const ArrayData& arr) {
    for (int i = 0; i < arr.getUsed(); i++)
        cout << arr[i] << endl;
}

int main() {
    cout << "202211305 박지원" << endl;
    ArrayData arr1(5);
    arr1.addElement(10.5);
    arr1.addElement(10.6);
    showArray(arr1);

    ArrayData arr2;
    arr2 = arr1;
    showArray(arr2);


    ArrayData arr3;
    arr3 = move(arr2);
    for (int i = arr3.getUsed(); i < arr3.getCapacity(); i++)
        arr3[i] = 10.99;
    cout << arr3 << endl;

    /*vector<ArrayData> vec;
    for (size_t i = 0; i < 4; i++) {
        cout << "iteration " << i << endl;
        vec.push_back(ArrayData(5));
        cout << endl;
    }*/

    /*ArrayData data1;
    data1.addElement(5.5);
    data1.addElement(5.5);
    data1.addElement(5.5);
    data1.showData();

    cout << "=================" << endl;
    ArrayData copy1(data1);
    showArr(copy1);
    cout << "=================" << endl;
    ArrayData copy2 = getArr(10)*/;

    /*ArrayData* parr = new ArrayData(10);
    parr->addElement(10.5);
    parr->addElement(10.5);
    parr->addElement(10.5);
    parr->addElement(10.5);
    parr->showData();
    delete parr;*/
}