import java.util.Scanner;

public class Main {
    static long mod = (long)Math.pow(10, 9) + 7;
    static long[] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        dp = new long[(int)(n + 1)];
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }
        long ans = dp[(int)n];
        if (n % 2 == 0) {
            ans = (ans * 2) % mod;
       
           ans = (ans * 5) % mod;
           ans = (ans + 1) % mod;
           ans = (ans * 5) % mod;
           ans = (ans - 1) % mod;
           ans = (ans + mod) % mod;
           ans = (ans / 2) % mod;
           System.out.println(ans);
       } else {
           ans = (ans * 2) % mod;
           ans = (ans * 5) % mod;
           ans = (ans - 1) % mod;
           ans = (ans + mod) % mod;
           ans = (ans / 2) % mod;
           System.out.println(ans);
       }
    }
}
