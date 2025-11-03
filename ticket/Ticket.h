#pragma once
class Ticket {
protected:
    int number = 0;
    double price;
public:
    Ticket(double price);
    ~Ticket();
    int getNumber() const;
    double getPrice() const;
    void setPrice(const double& price);
    void show() const;
};
