#include <iostream>
#include <cmath>
#include <ctime>
#include <thread>

#include "Card.h"

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

using namespace std;

void defineSize(int &amount, int &rows, int &cols);
Card **createBoard(int rows, int cols);
void shuffleBoard(Card **board, int rows, int cols);
void playGame(Card **board, int rows, int cols);
void finishGame(Card **board, int rows, int cols);

int main() {
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    srand(static_cast<unsigned>(time(nullptr)));
    cout << "202211305 박지원" << endl;

    int amount, rows, cols;
    defineSize(amount, rows, cols);
    Card **board = createBoard(rows, cols);
    shuffleBoard(board, rows, cols);

    playGame(board, rows, cols);
    finishGame(board, rows, cols);
    return 0;
}

void defineSize(int &amount, int &rows, int &cols) {
    /*
     * 요구사항 1-1: 게임 보드 크기 결정
     */
    while (true) {
        system("cls");
        cout << "카드 개수를 입력하세요: ";
        cin >> amount;

        if (cin.fail() || amount <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "값을 다시 입력하세요." << endl;
            continue;
        }

        if (amount % 2 == 0) break;
        cout << "짝수가 아닙니다. 다시 입력하세요." << endl;
    }

    int r = static_cast<int>(sqrt(amount));
    while (amount % 2 != 0) r--;
    cols = amount / r;
    rows = r;
}

Card **createBoard(const int rows, const int cols) {
    /*
     * 요구사항 1-2: 보드 배열 생성 및 카드 생성
     */
    Card **board = new Card *[rows];
    for (int i = 0; i < rows; i++)
        board[i] = new Card[cols];

    int count = 1;
    for (int i = 0; i < rows * cols; i++) {
        board[i / cols][i % cols] = Card(to_string(count));

        if (i % 2 == 1) {
            count++;
        }
    }
    return board;
}

void shuffleBoard(Card **board, const int rows, const int cols) {
    /*
     * 요구사항 1-3: 카드 위치 섞기
     */
    for (int i = 0; i < rows * cols; i++) {
        const int r1 = rand() % rows;
        const int r2 = rand() % rows;
        const int c1 = rand() % cols;
        const int c2 = rand() % cols;

        string temp = board[r1][c1].getValue();
        board[r1][c1].setValue(board[r2][c2].getValue());
        board[r2][c2].setValue(temp);
    }
}

void printBoard(Card **board, const int rows, const int cols) {
    cout << "\t";
    for (int i = 0; i < cols; i++)
        cout << i + 1 << "\t";
    cout << endl;
    for (int i = 0; i < rows; i++) {
        cout << static_cast<char>('A' + i) << "\t";
        for (int j = 0; j < cols; j++) {
            if (board[i][j].isMatched() || board[i][j].isFlipped()) cout << board[i][j].getValue() << "\t";
            else cout << "*" << "\t";
        }
        cout << endl;
    }
}

Card& inputCard(Card **board, const int rows, const int cols) {
    char x;
    int y;
    while (true) {
        cout << "카드를 선택해 주세요(예: A3): ";
        cin >> x >> y;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "값을 다시 입력하세요." << endl;
            continue;
        }

        const int r = x - 'A';
        const int c = y - 1;
        if (r >= rows || r < 0 || c >= cols || c < 0) {
            cout << "잘못된 위치입니다. 다시 입력해 주세요." << endl;
            continue;
        }

        if (board[r][c].isMatched() || board[r][c].isFlipped()) {
            cout << "이미 공개된 카드입니다. 다시 입력해 주세요." << endl;
            continue;
        }

        board[r][c].setFlipped(true);
        return board[r][c];
    }
}

void playGame(Card **board, const int rows, const int cols) {
    const int pairs = rows * cols / 2;
    int matched = 0;

    while (matched < pairs) {
        system("cls");
        printBoard(board, rows, cols);
        Card &first = inputCard(board, rows, cols);
        cout << "첫 번째 카드: " << first.getValue() << endl;
        Card &second = inputCard(board, rows, cols);
        cout << "두 번째 카드: " << second.getValue() << endl;

        if (first.getValue() == second.getValue()) {
            cout << "두 카드가 일치합니다." << endl;
            first.setMatched(true);
            second.setMatched(true);
            matched++;
        } else {
            cout << "두 카드가 일치하지 않습니다." << endl;
            first.setFlipped(false);
            second.setFlipped(false);
            this_thread::sleep_for(chrono::seconds(2));
        }
    }
    cout << "모든 카드를 맞혔습니다. 게임 종료" << endl;
}

void finishGame(Card **board, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        delete[] board[i];
    }
    delete[] board;
}