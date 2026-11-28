import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char[][] board = new char[9][9];
        for (int i = 0; i < 9; i++) {
            String line = scanner.next();
            for (int j = 0; j < 9; j++) {
                board[i][j] = line.charAt(j);
            }
       
       }
       solveSudoku(board);
       for (int i = 0; i < 9; i++) {
           for (int j = 0; j < 9; j++) {
               System.out.print(board[i][j]);
           }
           System.out.println();
       }
    }

    public static void solveSudoku(char[][] board) {
        solve(board, 0, 0);
    }

    private static boolean solve(char[][] board, int row, int col) {
        if (row == 9) {
            return true;
        }
        int nextRow, nextCol;
        if (col == 8) {
            nextRow = row + 1;
            nextCol = 0;
        } else {
            nextRow = row;
            nextCol = col + 1;
        }
        if (board[row][col] != '.') {
            if (solve(board, nextRow, nextCol)) {
                return true;
            } else {
                return false;
            }
        } else {
            for (char num = '1'; num <= '9'; num++) {
                if (isValid(board, row, col, num)) {
                    board[row][col] = num;
                    if (solve(board, nextRow, nextCol)) {
                        return true;
                    } else {
                        board[row][col] = '.';
                    }
                }
            }
            return false;
        }
    }

    private static boolean isValid(char[][] board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num || board[row][i] == num || board[(row/3)*3 + i/3][(col/3)*3 + i%3] == num) {
                return false;
            }
        }
        return true;
    }
}
