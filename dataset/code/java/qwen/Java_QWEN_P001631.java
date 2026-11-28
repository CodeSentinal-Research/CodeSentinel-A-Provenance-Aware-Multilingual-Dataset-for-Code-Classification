import java.util.*;
public class Main {
    static int m, n, target;
    static int[][] grid;
    static int count;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        m = sc.nextInt();
        n = sc.nextInt();
        target = sc.nextInt();
        grid = new int[m][n];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) grid[i][j] = sc.nextInt();
            
        count = 0;
        dfs(0, 0, 0);
        System.out.println(count);
    }
    
    static void dfs(int r, int c, int sum) {
        if(r == m-1 && c == n-1) {
            if(sum + grid[r][c] == target) count++;
            return;
        }
        if(r >= m || c >= n) return;
        
        dfs(r+1, c, sum + grid[r][c]);
        dfs(r, c+1, sum + grid[r][c]);
    }
}
