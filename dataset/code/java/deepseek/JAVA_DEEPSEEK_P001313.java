import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[][] grid = new int[9][9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                grid[i][j] = scanner.nextInt();
            }
        }

        if (solveSudoku(grid, 0, 0)) {
            printGrid(grid);
        } else {
            System.out.println("No solution exists.");
        }

        scanner.close();
    }

    private static boolean solveSudoku(int[][] grid, int row, int col) {
        if (row == 9 - 1 && col == 9) {
            return true;
        } else if (col == 9) {
            row++;
            col = 0;
        } else if (grid[row][col] != 0) {
            return solveSudoku(grid, row, col + 1);
        }

        for (int num = 1; num <= 9; num++) {
            if (isValid(grid, row, col, num)) {
                grid[row][col] = num;
                if (solveSudoku(grid, row, col + 1)) {
                    return true;
                }
                grid[row][col] = 0;
            }
        }

        return false;
    }

    private static boolean isValid(int[][] grid, int row, int col, int num) {
        for (int i = 0; i < 9; i++) {
            if (grid[row][i] == num) {
                return false;
            }
        }

        for (int i = 0; i < 9; i++) {
            if (grid[i][col] == num) {
                return false;
            }
        }

        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (grid[i][j] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    private static void printGrid(int[][] grid) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(grid[i][j] + " ");
            }
            System.out.println();
        }
    }
}
