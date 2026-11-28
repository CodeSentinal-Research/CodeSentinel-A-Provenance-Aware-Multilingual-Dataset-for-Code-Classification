#include <vector>
#include <string>

class Solution {
public:
    std::string tictactoe(std::vector<std::vector<int>>& moves) {
        std::vector<int> rows(3, 0), cols(3, 0);
        int diag = 0, antiDiag = 0;

        for (size_t i = 0; i < moves.size(); i++) {
            int r = moves[i][0], c = moves[i][1];
            int val = (i % 2 == 0) ? 1 : -1;

            rows[r] += val;
            cols[c] += val;
            if (r == c) diag += val;
            if (r + c == 2) antiDiag += val;

            if (rows[r] == 3 || cols[c] == 3 || diag == 3 || antiDiag == 3) return "A";
            if (rows[r] == -3 || cols[c] == -3 || diag == -3 || antiDiag == -3) return "B";
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};