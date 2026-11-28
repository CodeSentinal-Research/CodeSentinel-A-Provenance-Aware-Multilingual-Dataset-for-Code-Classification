import java.util.*;
public class Main {
    static int n;
    static int[][] board;
    static boolean solved;
    static int[] kr = {-2, -1, 1, 2, 2, 1, -1, -2};
    static int[] kc = {1, 2, 2, 1, -1, -2, -2, -1};
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int sr = sc.nextInt();
        int scCol = sc.nextInt();
        
        board = new int[n][n];
        for(int[] row : board) Arrays.fill(row, -1);
        board[sr][scCol] = 0;
        
        solved = false;
        backtrack(sr, scCol, 1);
        
        if(solved) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) System.out.print(board[i][j] + " ");
                System.out.println();
            }
        } else {
            System.out.println(-1);
        }
    }
    
    static void backtrack(int r, int c, int move) {
        if(move == n*n) {
            solved = true;
            return;
        }
        for(int i=0; i<8; i++) {
            int nr = r + kr[i];
            int nc = c + kc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == -1 && !solved) {
                board[nr][nc] = move;
                backtrack(nr, nc, move+1);
                if(!solved) board[nr][nc] = -1;
            }
        }
    }
}
