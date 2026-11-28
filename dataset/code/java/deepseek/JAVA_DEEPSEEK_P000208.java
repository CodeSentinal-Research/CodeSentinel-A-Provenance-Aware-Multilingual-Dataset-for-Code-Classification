import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        int[][] matrix = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        printDiagonal(matrix, rows, cols);
    }

    private static void printDiagonal(int[][] matrix, int rows, int cols) {
        int[] output = new int[rows * cols];
        int[] direction = {-1, 1};
        int row = 0, col = 0, dir = 0;
        for (int i = 0; i < rows * cols; i++) {
            output[i] = matrix[row][col];
            row += direction[dir];
            col -= direction[dir];
            if (row >= rows) {
                row = rows - 1;
                col += 2;
                dir = 1 - dir;
            }
            if (col >= cols) {
                col = cols - 1;
                row += 2;
                dir = 1 - dir;
           }
            if (row < 0) {
                row = 0;
                dir = 1 - dir;
            }
            if (col < 0) {
                col = 0;
                dir = 1 - dir;
            }
        }
        for (int i = 0; i < rows * cols; i++) {
            System.out.print(output[i] + " ");
        }
    }
}
