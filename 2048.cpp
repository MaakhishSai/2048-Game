#include <bits/stdc++.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

class Game2048 {
private:
    int board[4][4];
    int movesCount;
    int score;
    int dirsX[4] = {-1, 0, 1, 0}; // up, right, down, left
    int dirsY[4] = {0, 1, 0, -1};

    pair<int, int> generateEmptyPosition() {
        int filled = 1, row, col;
        while (filled) {
            row = rand() % 4;
            col = rand() % 4;
            if (board[row][col] == 0) {
                filled = 0;
            }
        }
        return make_pair(row, col);
    }

    void addPiece() {
        pair<int, int> pos = generateEmptyPosition();
        board[pos.first][pos.second] = 2;
    }

public:
    Game2048() {
        srand(time(0));
        newGame();
    }

    void newGame() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                board[i][j] = 0;
            }
        }
        movesCount = 0;
        score = 0;
        addPiece();
    }

    void print() {
        system("cls");
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] == 0) {
                    cout << setw(5) << '-';
                } else {
                    cout << setw(5) << board[i][j];
                }
            }
            cout << '\n';
        }
        cout << "n: NEW GAME\n"
             << "u : UP\n"
             << "d : DOWN\n"
             << "l : LEFT\n"
             << "r : RIGHT\n"
             << "e : EXIT\n";
    }

    bool canMove(int row, int col, int newRow, int newCol) {
        if (newRow < 0 || newCol < 0 || newRow >= 4 || newCol >= 4)
            return false;
        if (board[row][col] != 0 && (board[newRow][newCol] == 0 || board[newRow][newCol] == board[row][col]))
            return true;
        return false;
    }

    void move(int direction) {
        int startRow = 0, startCol = 0, rowStep = 1, colStep = 1;

        if (direction == 0) { // up
            startRow = 1;
            rowStep = 1;
        } else if (direction == 1) { // right
            startCol = 2;
            colStep = -1;
        } else if (direction == 2) { // down
            startRow = 2;
            rowStep = -1;
        } else if (direction == 3) { // left
            startCol = 1;
            colStep = 1;
        }

        bool canAddPiece = false;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int row = (rowStep == 1 ? i : 3 - i);
                int col = (colStep == 1 ? j : 3 - j);
                if (board[row][col] != 0) {
                    int newRow = row + dirsX[direction];
                    int newCol = col + dirsY[direction];
                    while (canMove(row, col, newRow, newCol)) {
                        if (board[newRow][newCol] == board[row][col]) {
                            board[newRow][newCol] *= 2;
                            board[row][col] = 0;
                            score += board[newRow][newCol];
                            canAddPiece = true;
                            break;
                        } else if (board[newRow][newCol] == 0) {
                            board[newRow][newCol] = board[row][col];
                            board[row][col] = 0;
                            row = newRow;
                            col = newCol;
                            newRow += dirsX[direction];
                            newCol += dirsY[direction];
                            canAddPiece = true;
                        }
                    }
                }
            }
        }

        if (canAddPiece) {
            addPiece();
            movesCount++;
        }
    }

    void start() {
        char inputMapp[128]; // for character mapping
        inputMapp['u'] = 0;  // up
        inputMapp['r'] = 1;  // right
        inputMapp['d'] = 2;  // down
        inputMapp['l'] = 3;  // left
        newGame();
        while (true) {
            print();
            char input;
            cin >> input;
            switch (input) {
            case 'n':
                newGame();
                break;
            case 'e':
                cout << "Total moves: " << movesCount << "\n";
                cout << "Total score: " << score << "\n";
                exit(0);
                break;
            case 'd':
            case 'u':
            case 'l':
            case 'r':
                int currDirection = inputMapp[input];
                move(currDirection);
                break;
            }
        }
    }
};

int main() {
    Game2048 game;
    game.start();
    return 0;
}
