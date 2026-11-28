import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] prices = new int[n + 1];
        for (int i = 1; i <= n; i++) prices[i] = sc.nextInt();
        
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] = Math.max(dp[i], prices[j] + dp[i - j]);
            }
        }
        System.out.println(dp[n]);
    }
}
