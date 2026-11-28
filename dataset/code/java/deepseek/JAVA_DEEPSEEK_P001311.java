import java.util.Scanner;

public class Main {
    private static int N;
    private static int[] board;
    private static int solutions;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        scanner.close();

        board = new int[N];
        placeQueens(0);

        System.out.println(solutions);
    }

    private static void placeQueens(int row) {
        if (row == N) {
            printBoard();
            solutions++;
            return;
        }

        for (int col = 0; col < N; col++) {
            if (isSafe(row, col)) {
                board[row] = col;
                placeQueens(row + 1);
            }
        }
    }

    private static boolean isSafe(int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i] == col) {
                return false;
            }

            if (Math.abs(board[i] - col) == row - i) {
                return false;
            }
        }

        return true;
    }

    private static void printBoard() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (j == board[i]) {
                    System.out.print("Q ");
                } else {
                    System.out.print("X ");
                }
            }
            System.out.println();
        }
        System.out.println();
    }
}
