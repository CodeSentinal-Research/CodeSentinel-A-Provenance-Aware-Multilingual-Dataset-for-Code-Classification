import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[][] matrix = new int[n][n];
        boolean[] used = new boolean[n * n + 1];
        backtrack(matrix, used, 0, 0, n);
    }

    private static void backtrack(int[][] matrix, boolean[] used, int row, int col, int n) {
        if (row == n && col == n) {
            printMatrix(matrix, n);
            System.exit(0);
        }
        if (col == n) {
            backtrack(matrix, used, row + 1, 0, n);
        } else {
            if (row == 0 || col == 0) {
                used[matrix[row][col]] = true;
                matrix[row][col] = row + col;
                backtrack(matrix, used, row, col + 1, n);
                used[matrix[row][col]] = false;
            } else {
                if (used[matrix[row - 1][col] + matrix[row][col - 1]]) {
                    backtrack(matrix, used, row, col + 1, n);
                } else {
                    used[matrix[row - 1][col] + matrix[row][col - 1]] = true;
                    matrix[row][col] = row + col;
                    backtrack(matrix, used, row, col + 1, n);
                    used[matrix[row - 1][col] + matrix[row][col - 1]] = false;
                }
            }
        }
    }

    private static void printMatrix(int[][] matrix, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
