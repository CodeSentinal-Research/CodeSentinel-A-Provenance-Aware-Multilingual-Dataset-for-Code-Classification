import java.util.Scanner;

public class Main {
    static int mod = (int)1e9+7;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] dp = new long[n+1];
        dp[0] = dp[1] = 0;
        for(int i=2; i<=n; i++)
            dp[i] = ((i-1L) * (dp[i-1] + dp[i-2])) % mod;
        System.out.println(dp[n]);
    }
}
