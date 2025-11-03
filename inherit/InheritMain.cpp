#include <iostream>
#include "DocWriter.h"
#include "HTMLWriter.h"
using namespace std;

int main() {
    HTMLWriter html("index.html", "greenjoa");
    html.SetFont("궁서체", 20, "blue");
//    html.Write();
    DocWriter doc = html;
    DocWriter* pDoc = &html;
    DocWriter& rDoc = html;
    rDoc.Write();
    return 0;
}