import java.util.*;

public class Main {
    static int N, L, S;
    static int[] snakes = new int[1001];
    static int[] ladders = new int[1001];
    static int[] dp = new int[1001];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        L = sc.nextInt();
        for (int i = 0; i < L; i++) {
            ladders[sc.nextInt()] = sc.nextInt();
        }
        S = sc.nextInt();
        for (int i = 0; i < S; i++) {
            snakes[sc.nextInt()] = sc.nextInt();
        }
        Arrays.fill(dp, -1);
        dp[1] = 0;
        for (int i = 1; i <= N; i++) {
            if (dp[i] != -1) {
                if (ladders[i] != 0) dp[ladders[i]] = dp[i] + 1;
                if (snakes[i] != 0) dp[snakes[i]] = dp[i] + 1;
            }
        }
        System.out.println(dp[N]);
    }
}
