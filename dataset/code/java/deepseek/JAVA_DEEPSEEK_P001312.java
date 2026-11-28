import java.util.Scanner;

public class Main {
    private static int N;
    private static int[][] board;
    private static int count;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        board = new int[N][N];
        count = 0;
        placeQueen(0);
        System.out.println(count);
    }

    private static void placeQueen(int row) {
        if (row == N) {
            count++;
            return;
        }
        for (int col = 0; col < N; col++) {
            if (isSafe(row, col)) {
                board[row][col] = 1;
                placeQueen(row + 1);
                board[row][col] = 0;
            }
        }
    }

    private static boolean isSafe(int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 1) {
                return false;
            }
        }
        return true;
    }
}
