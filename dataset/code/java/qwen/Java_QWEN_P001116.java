import java.util.*;
public class Main {
    static int R, C;
    static char[][] board;
    static boolean[][] visited;
    static int[] dr = {1, -1, 0, 0};
    static int[] dc = {0, 0, 1, -1};
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        R = sc.nextInt();
        C = sc.nextInt();
        board = new char[R][C];
        visited = new boolean[R][C];
        
        for (int i = 0; i < R; i++) {
            String line = sc.next();
            for (int j = 0; j < C; j++) {
                board[i][j] = line.charAt(j);
            }
        }
        
        // Mark 'O's connected to boundary
        for (int i = 0; i < R; i++) {
            if (board[i][0] == 'O') dfs(i, 0);
            if (board[i][C - 1] == 'O') dfs(i, C - 1);
        }
        for (int j = 0; j < C; j++) {
            if (board[0][j] == 'O') dfs(0, j);
            if (board[R - 1][j] == 'O') dfs(R - 1, j);
        }
        
        // Flip remaining 'O's to 'X' and restore marked ones
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                System.out.print(board[i][j]);
            }
            System.out.println();
        }
    }
    
    static void dfs(int r, int c) {
        if (r < 0 || r >= R || c < 0 || c >= C || board[r][c] != 'O') return;
        board[r][c] = '#';
        for (int i = 0; i < 4; i++) {
            dfs(r + dr[i], c + dc[i]);
        }
    }
}
