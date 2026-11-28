import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        if (n == 2) { System.out.println(1); return; }
        if (n == 3) { System.out.println(2); return; }
        
        int[] dp = new int[n + 1];
        dp[2] = 1; dp[3] = 2;
        for (int i = 4; i <= n; i++) {
            dp[i] = Math.max(2 * dp[i - 2], 3 * dp[i - 3]);
            if (i >= 4) dp[i] = Math.max(dp[i], 4 * dp[i - 4]);
        }
        System.out.println(dp[n]);
    }
}
