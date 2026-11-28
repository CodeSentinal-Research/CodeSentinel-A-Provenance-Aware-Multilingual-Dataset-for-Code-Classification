import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        char[][] board = new char[N][M];
        for (int i = 0; i < N; i++) {
            String row = scanner.next();
            for (int j = 0; j < M; j++) {
                board[i][j] = row.charAt(j);
            }
       }
        String word = scanner.next();
        System.out.println(exist(board, word));
    }

    public static boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private static boolean dfs(char[][] board, int i, int j, String word, int index) {
        if (index == word.length()) {
            return true;
        }
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != word.charAt(index)) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '*';
        boolean result = dfs(board, i - 1, j, word, index + 1) ||
                dfs(board, i + 1, j, word, index + 1) ||
                dfs(board, i, j - 1, word, index + 1) ||
                dfs(board, i, j + 1, word, index + 1);
        board[i][j] = temp;
        return result;
    }
}
