#pragma once
#include <iostream>
using std::ostream;

class CMyPoint {
private:
    int x, y;
public:
    CMyPoint() = default;
    ~CMyPoint() = default;
    CMyPoint(const int &x, const int &y);
    friend ostream& operator<<(ostream &out, const CMyPoint &pt);

    template<size_t N>
    friend void sortAsc(CMyPoint(&arr)[N]);
};
