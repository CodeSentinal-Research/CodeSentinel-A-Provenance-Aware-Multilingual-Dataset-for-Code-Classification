import java.util.*;
public class Main {
    static int r, c;
    static int[][] grid;
    static boolean[][] visited;
    static int nonObstacles;
    static int paths;
    static int[] dr = {1, -1, 0, 0};
    static int[] dc = {0, 0, 1, -1};
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        c = sc.nextInt();
        grid = new int[r][c];
        int sr = 0, scCol = 0, er = 0, ec = 0;
        nonObstacles = 0;
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                grid[i][j] = sc.nextInt();
                if(grid[i][j] == 1) { sr = i; scCol = j; }
                if(grid[i][j] == 2) { er = i; ec = j; }
                if(grid[i][j] != -1) nonObstacles++;
            }
        }
        
        visited = new boolean[r][c];
        paths = 0;
        visited[sr][scCol] = true;
        dfs(sr, scCol, 1, er, ec);
        System.out.println(paths);
    }
    
    static void dfs(int i, int j, int steps, int er, int ec) {
        if(i == er && j == ec) {
            if(steps == nonObstacles) paths++;
            return;
        }
        
        for(int d=0; d<4; d++) {
            int ni = i + dr[d];
            int nj = j + dc[d];
            if(ni >= 0 && ni < r && nj >= 0 && nj < c && !visited[ni][nj] && grid[ni][nj] != -1) {
                visited[ni][nj] = true;
                dfs(ni, nj, steps+1, er, ec);
                visited[ni][nj] = false;
            }
        }
    }
}
