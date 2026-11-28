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
            
        int maxArea = 0;
        int[][] prefix = new int[m+1][n+1];
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        for(int r1=0; r1<m; r1++) {
            for(int c1=0; c1<n; c1++) {
                for(int r2=r1; r2<m; r2++) {
                    for(int c2=c1; c2<n; c2++) {
                        int sum = prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
                        if(sum <= k) {
                            int area = (r2-r1+1) * (c2-c1+1);
                            maxArea = Math.max(maxArea, area);
                        }
                    }
                }
            }
        }
        System.out.println(maxArea);
    }
}
