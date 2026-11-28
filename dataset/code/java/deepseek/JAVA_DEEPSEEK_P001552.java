import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long x = scanner.nextLong();
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLong();
        }
        System.out.println(minSubarray(arr, n, x));
    }

    static long minSubarray(long arr[], int n, long X) {
        long sum = 0, minLen = n + 1;
        int start = 0, end = 0;
        while (end < n) {
            while (sum < X && end < n) {
                sum += arr[end++];
            }
            while (sum >= X && start < end) {
                minLen = Math.min(minLen, end - start);
                sum -= arr[start++];
            }
        }
        return minLen == n + 1 ? -1 : minLen;
    }
}
