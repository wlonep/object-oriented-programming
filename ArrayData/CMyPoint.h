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
    CMyPoint(const CMyPoint &pt);
    CMyPoint(const CMyPoint &&pt) noexcept;
    friend ostream& operator<<(ostream &out, const CMyPoint &pt);

    bool operator>(const CMyPoint& other) const;
    bool operator==(const CMyPoint& pt) const;
};
