#pragma once
#include <string>
using std::string;
class Salesman
{
private:
    string m_name;
    double m_sales;
    static inline int count = 0;
public:
    Salesman();
    Salesman(const Salesman& man);
    Salesman(const char* name);
    explicit Salesman(const string& name);
    Salesman(const string& name, const double& sales);
    ~Salesman();
    void setName(string& name);
    string getName() {
        return this->m_name;
    };
    string getName() const{
        return this->m_name;
    };
    void setSales(const double& sales);
    double getSales();
    void readInput();
    string getSalesmanInfo();
    friend void show(const Salesman& s);
    static int getCount() {
        return count;
    }
    void showFriend(Salesman s); //Salesman s = s3;
};

