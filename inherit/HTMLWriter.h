#pragma once

#include "DocWriter.h"

class HTMLWriter : public DocWriter {
protected:
    string fontName = "굴림체";
    int fontSize = 20;
    string fontColor = "red";
public:
    HTMLWriter();
    using DocWriter::DocWriter;
    //HTMLWriter(const string &fileName, const string &content);

    HTMLWriter(const string &fileName, const string &content, const string &fontName, const int fontSize,
               const string &fontColor);

    ~HTMLWriter();

    void Write();

    void SetFont(const string &fontName, int fontSize, const string &fontColor);
    HTMLWriter& operator<<(const string& str);
    HTMLWriter& operator<<(const int& num);
};