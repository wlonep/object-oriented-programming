#include <iostream>
#include "CMyPoint.h"
using namespace std;

CMyPoint::CMyPoint(const int &x, const int &y): x(x), y(y) {
    cout << "디폴트 생성자" << endl;
}

ostream& operator<<(ostream &out, const CMyPoint &pt) {
    out << "(" << pt.x << ", " << pt.y << ")";
    return out;
}


CMyPoint::CMyPoint(const CMyPoint &pt): x(pt.x), y(pt.y) {
    cout << "복사 생성자" << endl;
}

CMyPoint::CMyPoint(const CMyPoint &&pt) noexcept: x(pt.x), y(pt.y) {
    cout << "이동 생성자" << endl;
}

bool CMyPoint::operator>(const CMyPoint& other) const {
    return this->x > other.x;
}
