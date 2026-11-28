import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        scanner.nextLine();
        int[][] matrix = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        printZigzag(matrix);
    }

    private static void printZigzag(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;
        int row = 0, col = 0;
        for (int i = 0; i < rows * cols; i++) {
            System.out.print(matrix[row][col] + " ");
            if (dir == 0 || dir == 2) {
                if (col + 1 < cols && row - 1 >= 0 && matrix[row - 1][col + 1] != 0) {
                    col++;
                    row--;
                } else {
                    if (row == rows - 1) {
                        col++;
                    } else {
                        row++;
                    }
                    dir = (dir + 1) % 4;
                }
            } else {
                if (col - 1 >= 0 && row + 1 < rows && matrix[row + 1][col - 1] != 0) {
                    col--;
                    row++;
                } else {
                    if (col == cols - 1) {
                        row++;
                    } else {
                        col++;
                    }
                    dir = (dir + 1) % 4;
                }
            }
        }
    }
}
