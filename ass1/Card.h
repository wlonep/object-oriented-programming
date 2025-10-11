#pragma once
#include <string>

class Card {
private:
    std::string value;
    bool matched;
    bool flipped;
public:
    Card();
    explicit Card(const std::string &v);
    void setValue(const std::string &v);
    std::string getValue();
    void setMatched(bool m);
    bool isMatched() const;
    void setFlipped(bool f);
    bool isFlipped() const;
};
