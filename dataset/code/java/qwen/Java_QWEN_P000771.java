import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] keys = new int[n];
        double[] freq = new double[n];
        for(int i=0; i<n; i++) keys[i] = sc.nextInt();
        for(int i=0; i<n; i++) freq[i] = sc.nextDouble();
        System.out.println(optimalBST(freq, n));
    }
    static double optimalBST(double[] freq, int n) {
        double[][] dp = new double[n][n];
        for(int i=0; i<n; i++) dp[i][i] = freq[i];
        for(int L=2; L<=n; L++) {
            for(int i=0; i<=n-L; i++) {
                int j = i + L - 1;
                dp[i][j] = Double.MAX_VALUE;
                double sum = 0;
                for(int k=i; k<=j; k++) sum += freq[k];
                for(int r=i; r<=j; r++) {
                    double cost = (r > i ? dp[i][r-1] : 0) + (r < j ? dp[r+1][j] : 0) + sum;
                    dp[i][j] = Math.min(dp[i][j], cost);
                }
            }
        }
        return dp[0][n-1];
    }
}
