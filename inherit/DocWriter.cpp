#include "DocWriter.h"
#include <iostream>
#include <fstream>		// file stream (파일 입출력 기능 사용 위해)
using namespace std;

DocWriter::DocWriter() : DocWriter("noname.txt", "no content") {}
DocWriter::DocWriter(const string& fileName, const string& content)
        :fileName(fileName), content(content){
    cout << "DocWriter 생성자" << endl;
}
DocWriter::~DocWriter() {
    cout << "DocWriter 소멸자" << endl;
}
void DocWriter::SetFileName(const string& fileName){
    this->fileName = fileName;
}
void DocWriter::SetContent(const string& content){
    this->fileName = content;
}
void DocWriter::Write(){
    ofstream fout(fileName);	// ofstream : Output File Stream. (파일에 데이터 출력 기능하는 클래스)
    fout << content << endl;	// fout(filename) : file output 객체 생성하면서 생성자에 파일 이름 전달
}