#include <iostream>
#include <vector>

enum Player {
    X,
    O,
    NONE
};

Player determineWinner(const std::vector<std::string>& board) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (Player)i;
        }

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return (Player)i;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (Player)0;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (Player)0;
    }

    bool allSame = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                allSame = false;
                break;
            }
        }
        if (!allSame) break;
    }

    if (allSame) {
        return NONE;
    }

    return X;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> board(n, std::string(n, ' '));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> board[i][j];
        }
    }

    Player winner = determineWinner(board);

    if (winner == NONE) {
        std::cout << "DRAW" << std::endl;
    } else if (winner == X) {
        std::cout << "Player X wins" << std::endl;
    } else {
        std::cout << "Player O wins" << std::endl;
    }

    return 0;
}