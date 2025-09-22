
#include <iomanip>
#include <fstream>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif


void example01(int start, int end) {
    for (int i = 1; i < 10; i++) {
        for (int j = start; j < end + 1; j++) {
            cout << j << " * " << i << " = " << setw(2) << i * j << "\t";
        }
        cout << "\n";
    }
}

void example02() {
    string name, addr;
    int tel;
    cin >> name >> tel;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
    }
    getline(cin, addr);
    cout << name << "\t" << tel << "\t" << addr << endl;
}

void example03() {
    string mystr, name;
    int sum = 0;
    int temp;

    cout << "이름 성적: ";
    getline(cin, mystr);
    stringstream ss(mystr);
    ss >> name;

    while (ss >> temp) {
        sum += temp;
    }
    cout << name << ": " << sum << endl;
}

void example04() {
    ifstream fin("testdata.txt");
    if (!fin.is_open()) {
        cout << "파일 읽기 실패" << endl;
        return;
    }
    string data;
    while (!fin.eof()) {
        string str;
        getline(fin, str);
        data.append(str + "\n");
    }
    cout << data << endl;
    cout << "************" << endl;

    string findStr, replaceStr;
    cout << "찾을 문자열: ";
    getline(cin, findStr);
    cout << "바꿀 문자열: ";
    getline(cin, replaceStr);

    int pos = data.find(findStr);
    int count = 0;
    while (pos != string::npos) {
        data.replace(pos, findStr.length(), replaceStr);
        pos = data.find(findStr, pos + replaceStr.length());
        count++;
    }

    if (count == 0) {
        cout << "문자열이 없음" << endl;
        return;
    }

    cout << "************" << endl;
    cout << data << endl;
}

void example05() {
    constexpr int SIZE = 10;
    int num[SIZE];
    srand((unsigned)time(NULL));
    cout << "==============" << endl;
    cout << "인덱스 값" << endl;
    cout << "==============" << endl;
    int i = 0;
    for (auto& a : num) {
        a = rand() % 100;
        cout << i++ << "\t" << a << endl;
    }
    cout << endl;
}

void example06() {
    constexpr int ROW = 3;
    constexpr int COL = 3;
    bool seats[ROW][COL]{};

    while (true) {
        for (int i = 0; i < COL; i++)
            cout << "\t" << i + 1;
        cout << endl;

        for (int i = 0; i < ROW; i++) {
            cout << static_cast<char>('A' + i) << "\t";
            for (int j = 0; j < COL; j++) {
                cout << (seats[i][j] ? "O" : "X") << "\t";
            }
            cout << endl;
        }

        string seat;
        cout << "좌석을 선택하세요(예: A1) 종료하려면 'X'를 입력: ";
        cin >> seat;

        if (seat == "X") break;
        if (seat.size() < 2) {
            cout << "올바른 좌석을 입력해 주세요." << endl;
            continue;
        }

        int row = toupper(seat[0]) - 'A';
        int col = stoi(seat.substr(1)) - 1;
        if (row < 0 || row >= ROW || col < 0 || col >= COL) {
            cout << "존재하지 않는 좌석입니다." << endl;
            continue;
        }

        if (seats[row][col]) {
            cout << "이미 예약된 좌석입니다." << endl;
        }
        else {
            seats[row][col] = true;
            cout << "예약이 완료되었습니다." << endl;
        }
    }
}

int* makeArray(const int SIZE) {
    int* temp = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        temp[i] = rand() % 10;
    }
    return temp;
}

void printArray(int* (&arr), const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main() {
    cout << "202211305 박지원" << endl;
    /*showName();
    gdGoNS::showName();*/

    /*int start, end;
    cout << "구구단의 출력 범위를 입력하세요(시작, 끝): ";
    cin >> start >> end;
    if (start >= end) {
        cout << "끝 숫자가 더 큽니다. 시작과 끝 값을 바꿀까요? (y/n): ";
        char input;
        cin >> input;
        if (input == 'y') example01(end, start);
    }*/

    //example02();
    //example03();
    //example04();
    //example06();
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    int* arr = makeArray(10);
    printArray(arr, 10);
    return 0;
}