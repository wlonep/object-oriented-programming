#include "Card.h"

#include <string>

Card::Card() {
    value = "";
    matched = false;
    flipped = false;
}

Card::Card(const std::string &v) {
    value = v;
    matched = false;
    flipped = false;
}

void Card::setValue(const std::string &v) {
    value = v;
}

std::string Card::getValue() {
    return value;
}

void Card::setMatched(const bool m) {
    matched = m;
}

bool Card::isMatched() const {
    return matched;
}

void Card::setFlipped(const bool f) {
    flipped = f;
}

bool Card::isFlipped() const {
    return flipped;
}