#include "HTMLWriter.h"
#include <iostream>
#include <fstream>
using namespace std;

HTMLWriter::HTMLWriter() : DocWriter("noname.html", "no info") {

}

//HTMLWriter::HTMLWriter(const string &fileName, const string &content) : DocWriter(fileName, content) {}

HTMLWriter::HTMLWriter(const string &fileName, const string &content, const string &fontName, const int fontSize,
                       const string &fontColor) {
    cout << "생성자" << endl;
    this->fileName = fontName;
    this->fontColor = fontColor;
    this->fontSize = fontSize;

}

HTMLWriter::~HTMLWriter() {
    cout << "소멸자" << endl;
}

void HTMLWriter::Write() {
    ofstream fout(fileName);
    fout << "<html><head><title>home</title></head>";
    fout << "<body><h1>2022211305 박지원</h1><font face='";
    fout << fontName << "' size='" << fontSize << "' color='" << fontColor << "'>" << content;
    fout << "</font></body></html>";
}

void HTMLWriter::SetFont(const string &fontName, int fontSize, const string &fontColor) {
    this->fontName = fontName;
    this->fontSize = fontSize;
    this->fontColor = fontColor;
}

HTMLWriter& HTMLWriter::operator<<(const string& str) {
    content += str + "<br>";
    return *this;
}

HTMLWriter& HTMLWriter::operator<<(const int& num) {
    content += to_string(num) + "<br>";
    return *this;
}