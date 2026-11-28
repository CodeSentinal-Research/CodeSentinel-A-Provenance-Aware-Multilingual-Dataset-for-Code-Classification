import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int eggs = scanner.nextInt();
        int floors = scanner.nextInt();
        int[][] dp = new int[eggs + 1][floors + 1];
        for (int i = 1; i <= eggs; i++) {
            dp[i][1] = i;
        }
        for (int j = 2; j <= floors; j++) {
            dp[1][j] = j;
        }
        for (int i = 2; i <= eggs; i++) {
            for (int j = 2; j <= floors; j++) {
                int min = Integer.MAX_VALUE;
                for (int k = 1; k <= j; k++) {
                    int temp = 1 + Math.max(dp[i - 1][k - 1], dp[i][j - k]);
                    min = Math.min(min, temp);
                }
                dp[i][j] = min;
            }
        }
        System.out.println(dp[eggs][floors]);
    }
}
