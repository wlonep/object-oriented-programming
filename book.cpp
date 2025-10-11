#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <cctype>
#include <memory>
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

using sharedDPtr = shared_ptr<shared_ptr<int[]>[]>;

sharedDPtr loadSeats(const string& fileName, int& row, int& col, int& reserved);

void printSeats(sharedDPtr& seats, const int row, const int col);

void printMenu(sharedDPtr& seats, const int row, const int col, int reserved);

void reservedSeat(sharedDPtr& seats, int row, int col, int& reserved);

void saveSeat(const string& fileName, sharedDPtr& seats, const int row, const int col);

void cancelSeat(sharedDPtr& seats, const int row, const int col, int& reserved);

int main() {
    cout << "202211305 박지원" << endl;
    // SetConsoleOutputCP(CP_UTF8);
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    string fileName = "seats.txt";
    int row = 0, col = 0, reserved = 0;
    //int** seats = loadSeats(fileName, row, col, reserved);
    sharedDPtr seats = loadSeats(fileName, row, col, reserved);
    if (seats == nullptr) {
        cout << "파일 읽기 실패" << endl;
        return 0;
    }

    printMenu(seats, row, col, reserved);
    saveSeat(fileName, seats, row, col);
    return 0;
}

sharedDPtr loadSeats(const string& fileName, int& row, int& col, int& reserved) {
    ifstream file(fileName);
    if (!file.is_open()) {
        return nullptr;
    }
    file >> row >> col;
    sharedDPtr seats = make_shared<shared_ptr<int[]>[]>(row);
    for (int i = 0; i < row; i++) {
        seats[i] = make_shared<int[]>(col);
        for (int j = 0; j < col; j++) {
            file >> seats[i][j];
            if (seats[i][j] != 0)
                reserved++;
        }
    }
    return seats;
}

void printSeats(sharedDPtr& seats, const int row, const int col) {
    cout << "\t";
    for (int i = 0; i < col; i++)
        cout << i + 1 << "\t";
    cout << endl;
    for (int i = 0; i < row; i++) {
        cout << static_cast<char>('A' + i) << "\t";
        for (int j = 0; j < col; j++) {
            cout << (seats[i][j] != 0 ? "●" : "○") << "\t";
        }
        cout << endl;
    }
}

void printMenu(sharedDPtr& seats, const int row, const int col, int reserved) {
    int selected = 0;
    do {
        cout << "1)좌석현황\t2)좌석예약\t3)좌석취소\t4)종료" << endl << "메뉴 선택: ";
        cin >> selected;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        switch (selected) {
        case 1:
            printSeats(seats, row, col);
            break;
        case 2:
            reservedSeat(seats, row, col, reserved);
            break;
        case 3:
            cancelSeat(seats, row, col, reserved);
            break;
        case 4:
            break;
        }
        system("pause");
    } while (selected != 4);
}

void reservedSeat(sharedDPtr& seats, int row, int col, int& reserved) {
    if (row * col == reserved) {
        cout << "좌석 예약 마감" << endl;
        return;
    }

    char x;
    int y;
    while (true) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        cout << endl;
        printSeats(seats, row, col);
        cout << "좌석 선택 ex) A1 (종료: 00)" << endl;
        cout << "좌석 번호 입력: ";
        cin >> x >> y;

        if (x == '0' && y == 0) {
            cout << "메뉴로 이동합니다." << endl;
            break;
        }

        int r = x - 'A';
        int c = y - 1;
        if (r >= row || r < 0 || c >= col || c < 0) {
            cout << "잘못된 좌석 번호. 다시 입력해 주세요." << endl;
            system("pause");
        }
        else if (seats[r][c] != 0) {
            cout << "이미 예약된 좌석. 다시 입력해 주세요." << endl;
            system("pause");
        }
        else {
            int num = (r + 1) * 100 + (c + 1);
            seats[r][c] = num;
            reserved++;
            cout << "예약 완료. 예약번호: " << num << endl;
            break;
        }
    }
}

void saveSeat(const string& fileName, sharedDPtr& seats, const int row, const int col) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cout << "파일 오류" << endl;
        return;
    }

    file << row << " " << col << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            file << seats[i][j] << " ";
        }
        file << endl;
    }
}

void cancelSeat(sharedDPtr& seats, const int row, const int col, int& reserved) {
    if (reserved == 0) {
        cout << "예약된 좌석이 없습니다." << endl;
        return;
    }

    char x;
    int y;
    while (true) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        cout << endl;
        printSeats(seats, row, col);
        cout << "취소할 좌석 선택 ex) A1 (종료: 00)" << endl;
        cout << "좌석 번호 입력: ";
        cin >> x >> y;

        if (x == '0' && y == 0) {
            cout << "메뉴로 이동합니다." << endl;
            break;
        }

        int r = x - 'A';
        int c = y - 1;
        if (r >= row || r < 0 || c >= col || c < 0) {
            cout << "잘못된 좌석 번호입니다. 다시 입력해 주세요." << endl;
            continue;
        }
        if (seats[r][c] == 0) {
            cout << "예약되지 않은 좌석입니다. 다시 입력해 주세요." << endl;
            system("pause");
            continue;
        }

        int inputNum;
        cout << "예약번호 입력: ";
        cin >> inputNum;

        if (inputNum == seats[r][c]) {
            cout << "좌석 " << x << y << " 취소 완료. 예약번호: " << inputNum << endl;
            seats[r][c] = 0;
            reserved--;
            break;
        }
        else {
            cout << "예약번호가 일치하지 않습니다. 다시 입력해 주세요." << endl;
            continue;
        }
    }
}
