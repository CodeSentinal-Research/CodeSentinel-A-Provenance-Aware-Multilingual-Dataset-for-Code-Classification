import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }
        if (canPartition(arr, K)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    private static boolean canPartition(int[] arr, int K) {
        int n = arr.length;
        if (n % K != 0) {
            return false;
        }
        int target = n / K;
        int[] prefixSums = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            prefixSums[i] = prefixSums[i - 1] + arr[i - 1];
        }
        for (int i = 1; i <= n - target * K; i++) {
            if (prefixSums[i + target * K] - prefixSums[i] == target) {
                return true;
            }
        }
        return false;
    }
}
