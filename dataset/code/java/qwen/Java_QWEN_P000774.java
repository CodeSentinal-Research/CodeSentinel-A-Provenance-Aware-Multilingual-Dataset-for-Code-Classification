import java.util.*;
public class Main {
    static char[][] board;
    static boolean[][] visited;
    static String word;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        board = new char[n][m];
        for(int i=0; i<n; i++) {
            String line = sc.next();
            for(int j=0; j<m; j++) board[i][j] = line.charAt(j);
        }
        word = sc.next();
        visited = new boolean[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(backtrack(i, j, 0)) {
                    System.out.println("true");
                    return;
                }
            }
        }
        System.out.println("false");
    }
    static boolean backtrack(int r, int c, int idx) {
        if(idx == word.length()) return true;
        if(r < 0 || r >= board.length || c < 0 || c >= board[0].length || visited[r][c] || board[r][c] != word.charAt(idx))
            return false;
        visited[r][c] = true;
        if(backtrack(r+1, c, idx+1) || backtrack(r-1, c, idx+1) || backtrack(r, c+1, idx+1) || backtrack(r, c-1, idx+1))
            return true;
        visited[r][c] = false;
        return false;
    }
}
