import java.util.Scanner;

public class Main {
    static int N;
    static int[][] board;
    static int[] xMove = {2, 1, -1, -2, -2, -1, 1, 2};
    static int[] yMove = {1, 2, 2, 1, -1, -2, -2, -1};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        int startRow = scanner.nextInt();
        int startCol = scanner.nextInt();

        board = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = -1;
            }
        }

        board[startRow][startCol] = 0;

        if (!solveKT(1, startRow, startCol)) {
            System.out.println(-1);
        } else {
            printSolution();
        }
    }

    static boolean solveKT(int stepCount, int x, int y) {
        if (stepCount == N * N) {
            return true;
        }

        for (int i = 0; i < 8; i++) {
            int nextX = x + xMove[i];
            int nextY = y + yMove[i];

            if (isValidMove(nextX, nextY)) {
                board[nextX][nextY] = stepCount;
                if (solveKT(stepCount + 1, nextX, nextY)) {
                    return true;
                } else {
                    board[nextX][nextY] = -1;
                }
            }
        }

        return false;
    }

    static boolean isValidMove(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1;
    }

    static void printSolution() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }
}
