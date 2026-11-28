import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] grid = new int[n][m];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) grid[i][j] = sc.nextInt();
        int threshold = sc.nextInt();
        
        int[][] prefix = new int[n+1][m+1];
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        int maxSide = 0;
        for(int side=1; side<=Math.min(n,m); side++) {
            boolean found = false;
            for(int i=side; i<=n; i++) {
                for(int j=side; j<=m; j++) {
                    int sum = prefix[i][j] - prefix[i-side][j] - prefix[i][j-side] + prefix[i-side][j-side];
                    if(sum <= threshold) {
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
            if(found) maxSide = side;
            else break;
        }
        System.out.println(maxSide);
    }
}
