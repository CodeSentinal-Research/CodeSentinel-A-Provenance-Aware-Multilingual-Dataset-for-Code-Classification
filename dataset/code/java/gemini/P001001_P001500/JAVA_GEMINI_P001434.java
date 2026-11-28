public class Solution {
    public String tictactoe(int[][] moves) {
        int[] rows = new int[3], cols = new int[3];
        int diag = 0, antiDiag = 0;

        for (int i = 0; i < moves.length; i++) {
            int r = moves[i][0], c = moves[i][1];
            int val = (i % 2 == 0) ? 1 : -1;

            rows[r] += val;
            cols[c] += val;
            if (r == c) diag += val;
            if (r + c == 2) antiDiag += val;

            if (rows[r] == 3 || cols[c] == 3 || diag == 3 || antiDiag == 3) return "A";
            if (rows[r] == -3 || cols[c] == -3 || diag == -3 || antiDiag == -3) return "B";
        }
        return moves.length == 9 ? "Draw" : "Pending";
    }
}