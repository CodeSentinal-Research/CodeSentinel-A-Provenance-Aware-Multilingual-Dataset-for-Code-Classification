import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] grid = new int[n][m];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) grid[i][j] = sc.nextInt();
        int k = sc.nextInt();
        
        int[][] prefix = new int[n+1][m+1];
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        int[][] res = new int[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int r1 = Math.max(0, i-k), c1 = Math.max(0, j-k);
                int r2 = Math.min(n-1, i+k), c2 = Math.min(m-1, j+k);
                res[i][j] = prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) System.out.print(res[i][j] + " ");
            System.out.println();
        }
    }
}
