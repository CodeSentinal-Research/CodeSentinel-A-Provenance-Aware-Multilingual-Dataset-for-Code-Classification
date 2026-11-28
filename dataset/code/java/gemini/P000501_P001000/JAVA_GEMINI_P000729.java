import java.util.*;
public class Solution {
    static boolean isValid(char[][] board, int r, int c, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == ch || board[i][c] == ch) return false;
            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == ch) return false;
        }
        return true;
    }
    static boolean solve(char[][] board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, r, c, ch)) {
                            board[r][c] = ch;
                            if (solve(board)) return true;
                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char[][] board = new char[9][9];
        for (int i = 0; i < 9; i++) {
            if (scanner.hasNext()) {
                board[i] = scanner.next().toCharArray();
            }
        }
        solve(board);
        for (int i = 0; i < 9; i++) System.out.println(new String(board[i]));
    }
}