import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int amount = scanner.nextInt();
        int[] denominations = new int[N];
        for (int i = 0; i < N; i++) {
            denominations[i] = scanner.nextInt();
        }
        Arrays.sort(denominations);
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int denom : denominations) {
                if (denom > i) break;
                if (dp[i - denom] != -1) {
                    if (dp[i] == -1 || dp[i] > dp[i - denom] + 1) {
                        dp[i] = dp[i - denom] + 1;
                    }
                }
            }
        }
        if (dp[amount] != -1) {
            System.out.println(dp[amount]);
        } else {
            System.out.println(-1);
        }
    }
}
