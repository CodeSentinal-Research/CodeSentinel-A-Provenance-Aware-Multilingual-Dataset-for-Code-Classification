#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int rows[9] = {0}, cols[9] = {0}, boxes[9] = {0};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c != '.') {
                int bit = 1 << (c - '0');
                int boxIdx = (i / 3) * 3 + (j / 3);

                if ((rows[i] & bit) || (cols[j] & bit) || (boxes[boxIdx] & bit)) {
                    return false;
                }
                rows[i] |= bit;
                cols[j] |= bit;
                boxes[boxIdx] |= bit;
            }
        }
    }
    return true;
}