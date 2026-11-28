import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        long[][] dp = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                dp[i][j] = 1;
                for (int k = i; k < j; k++) {
                    if (arr[j] - arr[k] == arr[j] - arr[i] && arr[j] - arr[k] < arr[j] - arr[k + 1]) {
                        dp[i][j] += dp[i][k] * dp[k + 1][j];
                    }
                }
            }
        }
        long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                sum += dp[i][j];
            }
        }
        System.out.println(sum);
    }
}
