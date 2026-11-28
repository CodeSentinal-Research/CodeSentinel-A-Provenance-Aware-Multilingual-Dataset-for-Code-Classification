import java.util.*;
public class Solution {
    static int[] dr = {1, -1, 0, 0};
    static int[] dc = {0, 0, 1, -1};
    static boolean backtrack(char[][] board, String word, int r, int c, int idx) {
        if (idx == word.length()) return true;
        if (r < 0 || r >= board.length || c < 0 || c >= board[0].length || board[r][c] != word.charAt(idx)) return false;
        char temp = board[r][c];
        board[r][c] = '#';
        for (int i = 0; i < 4; i++) {
            if (backtrack(board, word, r + dr[i], c + dc[i], idx + 1)) return true;
        }
        board[r][c] = temp;
        return false;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt(), m = scanner.nextInt();
            char[][] board = new char[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) board[i][j] = scanner.next().charAt(0);
            }
            String word = scanner.next();
            boolean found = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (backtrack(board, word, i, j, 0)) { found = true; break; }
                }
                if (found) break;
            }
            System.out.println(found ? "true" : "false");
        }
    }
}