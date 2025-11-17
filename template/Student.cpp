#include "Student.h"

Student::Student() : name(""), score(0) {
}

Student::~Student() = default;

Student::Student(const string &name, const int &score) : name(name), score(score) {
}

string Student::getName() const {
    return name;
}

int Student::getScore() const {
    return score;
}

bool Student::operator==(const string &n) const {
    return getName() == n;
}

bool Student::operator==(const Student &s) const {
    return getName() == s.getName();
}

ostream& operator<<(ostream& os, const Student& s) {
    os << s.getName() << " " << s.getScore();
    return os;
}