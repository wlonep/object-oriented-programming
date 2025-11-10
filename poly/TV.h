#pragma once
#include "Product.h"
#include <iostream>
using std::string;

class TV : public Product
{
private:
    int m_size;
public:
    TV(const string& name, const int& price, const int& size);
    ~TV();
    int getPrice() const override;
    void show() const override;
};
