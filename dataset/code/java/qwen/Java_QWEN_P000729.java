import java.util.*;
public class Main {
    static char[][] board;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        board = new char[9][9];
        for(int i=0; i<9; i++) {
            String line = sc.next();
            for(int j=0; j<9; j++) board[i][j] = line.charAt(j);
        }
        solveSudoku(0, 0);
        printBoard();
    }
    static boolean solveSudoku(int r, int c) {
        if(r == 9) return true;
        if(c == 9) return solveSudoku(r + 1, 0);
        if(board[r][c] != '.') return solveSudoku(r, c + 1);
        for(char ch='1'; ch<='9'; ch++) {
            if(isValid(r, c, ch)) {
                board[r][c] = ch;
                if(solveSudoku(r, c + 1)) return true;
                board[r][c] = '.';
            }
        }
        return false;
    }
    static boolean isValid(int r, int c, char ch) {
        for(int i=0; i<9; i++) {
            if(board[r][i] == ch || board[i][c] == ch) return false;
            if(board[3*(r/3) + i/3][3*(c/3) + i%3] == ch) return false;
        }
        return true;
    }
    static void printBoard() {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) System.out.print(board[i][j]);
            System.out.println();
        }
    }
}
