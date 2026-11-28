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
        System.out.println(maxLength(arr));
    }

    public static int maxLength(int[] arr) {
        int n = arr.length;
        int[] dp = new int[n];
        int[] prefix = new int[n];
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || (arr[i] % 2 != arr[i - 1] % 2)) {
                dp[i] = 1;
                if (i > 0) {
                    prefix[i] = prefix[i - 1] + 1;
                }
            } else {
                dp[i] = prefix[i - 1] + 1;
                prefix[i] = dp[i - 1] + 1;
            }
            max = Math.max(max, dp[i]);
        }
        return max;
    }
}
