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
        if (canBeSplit(arr)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    private static boolean canBeSplit(int[] arr) {
        int n = arr.length;
        int[] dp = new int[n];
        dp[0] = arr[0];
        for (int i = 1; i < n; i++) {
            dp[i] = Math.max(dp[i - 1], arr[i]);
        }
        int max = dp[n - 1];
        if (max < arr[n - 1] + arr[n - 2]) {
            return false;
        }
        max = Math.max(max, arr[0] + arr[1]);
        for (int i = 2; i < n - 1; i++) {
            max = Math.max(max, arr[i] + arr[i + 1]);
        }
        return max >= arr[0];
    }
}
