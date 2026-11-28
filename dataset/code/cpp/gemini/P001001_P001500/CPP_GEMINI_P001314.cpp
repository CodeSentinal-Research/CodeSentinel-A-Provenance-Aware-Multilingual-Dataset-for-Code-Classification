#include <vector>
#include <unordered_set>
#include <string>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
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
};