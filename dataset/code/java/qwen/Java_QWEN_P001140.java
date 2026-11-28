import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int W = sc.nextInt();
        int[] wt = new int[n];
        int[] val = new int[n];
        for (int i = 0; i < n; i++) {
            wt[i] = sc.nextInt();
            val[i] = sc.nextInt();
        }
        
        int[] dp = new int[W + 1];
        for (int i = 0; i < n; i++) {
            for (int w = wt[i]; w <= W; w++) {
                dp[w] = Math.max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
        System.out.println(dp[W]);
    }
}
