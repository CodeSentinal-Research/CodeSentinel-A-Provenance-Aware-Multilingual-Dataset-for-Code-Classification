import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = (int)1e9 + 7;
    static long[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int M = Integer.parseInt(st.nextToken());
        dp = new long[200010][200010];
        for (int i = 0; i <= 200000; i++) dp[i][0] = dp[i][i] = 1;
        for (int i = 2; i <= 200000; i++) {
            for (int j = 1; j < i; j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * j % MOD) % MOD;
            }
        }
        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            long ans = 0;
            for (int i = 1; i <= n; i++) {
                ans = (ans + dp[n][i]) % MOD;
            }
            System.out.println(ans);
        }
    }
}
