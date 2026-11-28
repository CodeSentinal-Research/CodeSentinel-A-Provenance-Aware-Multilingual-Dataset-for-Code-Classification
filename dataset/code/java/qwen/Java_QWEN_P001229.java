import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int r = sc.nextInt();
        int c = sc.nextInt();
        
        double[][][] dp = new double[k+1][n][n];
        dp[0][r][c] = 1.0;
        int[] dr = {-2, -1, 1, 2, 2, 1, -1, -2};
        int[] dc = {1, 2, 2, 1, -1, -2, -2, -1};
        
        for(int step=1; step<=k; step++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    for(int m=0; m<8; m++) {
                        int ni = i + dr[m];
                        int nj = j + dc[m];
                        if(ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            dp[step][ni][nj] += dp[step-1][i][j] / 8.0;
                        }
                    }
                }
            }
        }
        
        double prob = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                prob += dp[k][i][j];
        System.out.printf("%.6f
", prob);
    }
}
