#include <iostream>
#include "ArrayData.h"

using namespace std;

ArrayData::ArrayData() : ArrayData(3) {}

ArrayData::ArrayData(const int &capacity, const int &used) : capacity(capacity), used(used) {
    cout << "생성자" << endl;
    //data = new double[this->capacity];
    data = make_unique<double[]>(this->capacity);
    //data = make_shared<double[]>(this->capacity);
}

ArrayData::ArrayData(ArrayData &arr) : ArrayData(arr.capacity, arr.used) {
    cout << "복사생성자" << endl;
    for (size_t i = 0; i < used; i++) {
        data[i] = arr.data[i];
    }
}

ArrayData::ArrayData(ArrayData &&arr) noexcept: capacity(arr.capacity), used(arr.used), data(move(arr.data)) {
    cout << "이동생성자" << endl;
    //arr.data = nullptr;
}

ArrayData::~ArrayData() {
    /*if (data != nullptr)
        delete[] data;
    data = nullptr;*/
}

void ArrayData::addElement(const double &num) {
    if (!full())
        data[used++] = num;
    else
        cout << "빈방이 없음\n";
}

bool ArrayData::full() const {
    return this->capacity == this->used;
}

void ArrayData::emptyArray() {
    this->used = 0;
}

void ArrayData::showData() const {
    for (size_t i = 0; i < used; i++)
        cout << data[i] << " ";
    cout << endl;
}

// 복사 대입 연산자
ArrayData &ArrayData::operator=(const ArrayData &rhs) {

}

ArrayData &ArrayData::operator=(ArrayData &&rhs) noexcept {

}

double &ArrayData::operator[](size_t num) {

}

const double &ArrayData::operator[](size_t num) const {

}

ostream &operator<<(ostream &out, ArrayData &arr) {
    for (int i = 0; i < arr.getUsed(); i++)
        out << arr[i] << endl;
    return out;
}