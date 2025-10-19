#pragma once

#include <memory>

using namespace std;

class ArrayData {
private:
    //double* data=nullptr;
    unique_ptr<double[]> data;
    //shared_ptr<double[]> data;
    int capacity;
    int used;
public:
    ArrayData();

    ArrayData(ArrayData &arr);

    ArrayData(ArrayData &&arr) noexcept;

    ArrayData(const int &capacity, const int &used = 0);

    ~ArrayData();

    void addElement(const double &num);

    bool full() const;

    void emptyArray();

    void showData() const;

    int getCapacity() const {
        return this->capacity;
    };

    int getUsed() const {
        return this->used;
    };

    ArrayData &operator=(const ArrayData &rhs);

    ArrayData &operator=(ArrayData &&rhs) noexcept;

    double &operator[](size_t num);

    const double &operator[](size_t num) const;
};

ostream &operator<<(ostream &out, ArrayData &arr);