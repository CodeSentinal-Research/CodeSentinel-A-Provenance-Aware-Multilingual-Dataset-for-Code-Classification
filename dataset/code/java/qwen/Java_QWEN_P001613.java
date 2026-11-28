import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[][] mat = new int[m][n];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) mat[i][j] = sc.nextInt();
            
        int[][] prefix = new int[m+1][n+1];
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        int[][] res = new int[m][n];
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int r1 = Math.max(0, i-k);
                int c1 = Math.max(0, j-k);
                int r2 = Math.min(m-1, i+k);
                int c2 = Math.min(n-1, j+k);
                res[i][j] = prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
            }
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) System.out.print(res[i][j] + " ");
            System.out.println();
        }
    }
}
