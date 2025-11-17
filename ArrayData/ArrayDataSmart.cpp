#include "ArrayDataSmart.h"
#include <iostream>

using namespace std;

ArrayDataSmart::ArrayDataSmart() : ArrayDataSmart(3) {

}

ArrayDataSmart::ArrayDataSmart(ArrayDataSmart &arr) : ArrayData(arr), usedB(arr.usedB),
                                                      backdata(make_unique<double[]>(arr.capacity)) {
    cout << "ArrayDataSmart 복사생성자" << endl;
    for (int i = 0; i < usedB; i++) {
        backdata[i] = arr.backdata[i];
    }
}

ArrayDataSmart::ArrayDataSmart(ArrayDataSmart &&arr) noexcept: ArrayData(std::move(arr)), usedB(arr.usedB),
                                                               backdata(std::move(arr.backdata)) {
    cout << "ArrayDataSmart 이동생성자" << endl;
}

ArrayDataSmart::ArrayDataSmart(const int &capacity, const int &used) : ArrayData(capacity, used), usedB(0),
                                                                       backdata(make_unique<double[]>(capacity)) {
    cout << "ArrayDataSmart 생성자" << endl;
}

ArrayDataSmart::~ArrayDataSmart() {
    cout << "ArrayDataSmart 소멸자" << endl;
}

void ArrayDataSmart::backup() {
    if (backdata != nullptr) {
        usedB = used;
        for (int i = 0; i < usedB; i++) {
            backdata[i] = data[i];
        }
    }
}

void ArrayDataSmart::restore() {
    if (backdata != nullptr) {
        used = usedB;
        for (int i = 0; i < used; i++) {
            data[i] = backdata[i];
        }
    }
}

ArrayDataSmart &ArrayDataSmart::operator=(const ArrayDataSmart &rhs) {
    cout << "ArrayDataSmart 대입연산자" << endl;
    if (this == &rhs) return *this;
    ArrayData::operator=(rhs);
    usedB = rhs.usedB;
    backdata = make_unique<double[]>(rhs.capacity);
    for (int i = 0; i < usedB; i++) {
        backdata[i] = rhs.backdata[i];
    }
}

ArrayDataSmart &ArrayDataSmart::operator=(ArrayDataSmart &&rhs) noexcept {
    cout << "ArrayDataSmart 이동대입연산자" << endl;
    if (this == &rhs) return *this;
    ArrayData::operator=(std::move(rhs));
    usedB = rhs.usedB;
    backdata = std::move(rhs.backdata);
    return *this;
}
