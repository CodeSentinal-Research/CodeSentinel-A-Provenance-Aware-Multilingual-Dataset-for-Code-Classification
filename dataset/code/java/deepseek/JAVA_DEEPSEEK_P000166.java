import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLong();
        }
        System.out.println(minProductSubArray(arr, n));
    }

    static long minProductSubArray(long arr[], int n) {
        long min_ending_here = arr[0];
        long min_ending_so_far = arr[0];
        long max_ending_here = arr[0];
        long max_ending_so_far = arr[0];
        long result = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] > 0) {
                max_ending_here = max_ending_here * arr[i];
                min_ending_here = Math.min(min_ending_here * arr[i], arr[i]);
            } else {
                long temp = max_ending_here;
                max_ending_here = Math.max(min_ending_here * arr[i], arr[i]);
                min_ending_here = temp * arr[i];
            }

            if (max_ending_here > max_ending_so_far)
                max_ending_so_far = max_ending_here;
            if (min_ending_here < min_ending_so_far)
                min_ending_so_far = min_ending_here;
        }

        return max_ending_so_far;
    }
}
