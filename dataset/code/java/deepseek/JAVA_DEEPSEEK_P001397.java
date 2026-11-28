import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int R = scanner.nextInt();
        for (int i = 0; i < R; i++) {
            int N = scanner.nextInt();
            int[] bricks = new int[N];
            for (int j = 0; j < N; j++) {
                bricks[j] = scanner.nextInt();
            }
            System.out.println(minBricks(bricks));
        }
    }

    private static int minBricks(int[] bricks) {
        int[] dp = new int[bricks.length + 1];
        dp[0] = 0;
        for (int i = 0; i < bricks.length; i++) {
            dp[i + 1] = Math.max(dp[i + 1], dp[i] + bricks[i]);
        }
        return dp[bricks.length];
    }
}
