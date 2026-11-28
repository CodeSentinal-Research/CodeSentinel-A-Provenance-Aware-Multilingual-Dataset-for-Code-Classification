import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int d = sc.nextInt();
        int f = sc.nextInt();
        int s = sc.nextInt();
        
        long[][] dp = new long[d+1][s+1];
        dp[0][0] = 1;
        for(int i=1; i<=d; i++) {
            for(int j=1; j<=s; j++) {
                for(int k=1; k<=f && k<=j; k++) {
                    dp[i][j] += dp[i-1][j-k];
                }
            }
        }
        System.out.println(dp[d][s]);
    }
}
