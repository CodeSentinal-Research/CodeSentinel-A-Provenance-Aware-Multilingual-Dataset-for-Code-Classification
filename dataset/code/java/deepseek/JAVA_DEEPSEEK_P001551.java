import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        long K = scanner.nextLong();
        long[] arr = new long[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextLong();
        }
        System.out.println(longestSubarray(arr, N, K));
    }

    public static long longestSubarray(long[] arr, int N, long K) {
        long max = 0;
        long sum = 0;
        long min = 0;
        long[] prefix = new long[N];
        prefix[0] = arr[0];
        for (int i = 1; i < N; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        for (int i = 0; i < N; i++) {
            if (i > 0) {
                sum += prefix[i - 1];
            }
            if (sum < K) {
                max = Math.max(max, sum);
            } else {
                min = Math.min(min, sum - K);
            }
        }
        if (max == 0) {
            return -1;
        } else {
            return max - min;
        }
    }
}
