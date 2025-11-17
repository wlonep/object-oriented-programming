#pragma once
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int score;
public:
    Student();
    ~Student();
    Student(const string& name, const int& score);
    string getName() const;
    int getScore() const;

    bool operator==(const string& n) const;
    bool operator==(const Student& s) const;

};

ostream& operator<<(ostream& os, const Student& s);