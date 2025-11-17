#include "CMyPoint.h"

CMyPoint::CMyPoint(const int &x, const int &y): x(x), y(y) {
}

ostream& operator<<(ostream &out, const CMyPoint &pt) {
    out << "(" << pt.x << ", " << pt.y << ")";
    return out;
}

bool CMyPoint::operator>(const CMyPoint& other) const {
    return this->x > other.x;
}