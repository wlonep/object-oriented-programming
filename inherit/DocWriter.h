#pragma once
#include <string>
using std::string;
class DocWriter
{
protected:
    string fileName;
    string content;
public:
    DocWriter();
    DocWriter(const string& fileName, const string& content);
    ~DocWriter();

    void SetFileName(const string& fileName);	// 파일 이름을 지정
    void SetContent(const string& content);		// 저장할 텍스트를 지정
    void Write();								// 파일에 텍스트를 저장시킨다.
};


