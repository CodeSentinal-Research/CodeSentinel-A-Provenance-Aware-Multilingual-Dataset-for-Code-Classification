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
        
        int maxSide = 0;
        for(int side=1; side<=Math.min(m,n); side++) {
            boolean found = false;
            for(int i=side; i<=m; i++) {
                for(int j=side; j<=n; j++) {
                    int sum = prefix[i][j] - prefix[i-side][j] - prefix[i][j-side] + prefix[i-side][j-side];
                    if(sum <= k) {
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
