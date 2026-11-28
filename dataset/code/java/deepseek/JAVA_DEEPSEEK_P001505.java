import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        long[] arr = new long[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextLong();
        }
        System.out.println(countSubarrays(arr, N, K));
    }

    private static long countSubarrays(long[] arr, int N, long K) {
        long count = 0;
        long product = 1;
        int start = 0, end = 0;

        while (end < N) {
            product *= arr[end];

            while (product >= K && start < end) {
                product /= arr[start];
                start++;
            }

            count += end - start + 1;
            end++;
        }

        return count;
    }
}
