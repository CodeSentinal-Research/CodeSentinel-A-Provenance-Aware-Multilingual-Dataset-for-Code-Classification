import java.util.*;
public class Main {
    static int r, c;
    static int[][] grid;
    static boolean[][] visited;
    static int maxGold;
    static int[] dr = {1, -1, 0, 0};
    static int[] dc = {0, 0, 1, -1};
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        c = sc.nextInt();
        grid = new int[r][c];
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++) grid[i][j] = sc.nextInt();
        
        maxGold = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] > 0) {
                    visited = new boolean[r][c];
                    dfs(i, j, 0);
                }
            }
        }
        System.out.println(maxGold);
    }
    
    static void dfs(int i, int j, int currGold) {
        if(i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 0 || visited[i][j]) {
            maxGold = Math.max(maxGold, currGold);
            return;
        }
        
        visited[i][j] = true;
        currGold += grid[i][j];
        
        for(int d=0; d<4; d++) {
            dfs(i + dr[d], j + dc[d], currGold);
        }
        
        visited[i][j] = false;
    }
}
