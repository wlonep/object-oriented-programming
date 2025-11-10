#include "Product.h"
#include <iostream>
using std::string;

class Vegetable : public Product
{
private:
    string m_origin;
    int m_weight;
public:
    Vegetable(const string& name, const int& price,
              const string& origin, const int& weight);
    ~Vegetable() override;
    int getPrice() const override;
    void show() const override;
};