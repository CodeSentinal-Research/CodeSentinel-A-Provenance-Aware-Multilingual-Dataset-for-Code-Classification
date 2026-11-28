import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] mat = new int[m][n];
        int ones = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                mat[i][j] = sc.nextInt();
                if(mat[i][j] == 1) ones++;
            }
        }
        
        long count = 0;
        // Total submatrices - submatrices with unequal 0s and 1s?
        // Easier: Count submatrices with sum S such that S = Area/2 => 2*S = Area
        // Brute force for small constraints
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
                        int area = (r2-r1+1) * (c2-c1+1);
                        if(2 * sum == area) count++;
                    }
                }
            }
        }
        System.out.println(count);
    }
}
