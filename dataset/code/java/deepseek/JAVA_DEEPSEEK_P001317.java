import java.util.Scanner;

public class Main {
    private static int N;
    private static int[][] board;
    private static int[][] moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        int startRow = scanner.nextInt();
        int startCol = scanner.nextInt();
        board = new int[N][N];
        if (knightsTour(startRow, startCol)) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    System.out.print(board[i][j] + " ");
                }
                System.out.println();
            }
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }

    private static boolean knightsTour(int row, int col) {
        if (board[row][col] != 0) {
            return false;
        }
        board[row][col] = 1;
        if (board[row][col] == N * N) {
            return true;
        }
        for (int i = 0; i < 8; i++) {
            int newRow = row + moves[i][0];
            int newCol = col + moves[i][1];
            if (isValidMove(newRow, newCol)) {
                if (knightsTour(newRow, newCol)) {
                    return true;
                }
            }
        }
        board[row][col] = 0;
        return false;
    }

    private static boolean isValidMove(int row, int col) {
        return row >= 0 && row < N && col >= 0 && col < N && board[row][col] == 0;
    }
}
