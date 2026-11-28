import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLong();
        }
        long maxProduct = maxProduct(arr, k);
        System.out.println(maxProduct);
    }

    private static long maxProduct(long[] arr, long k) {
        long max = 0;
        long min = 0;
        long sum = 0;
        for (long num : arr) {
            max = Math.max(max, num);
            min = Math.min(min, num);
            sum += num;
        }
        long range = max - min;
        long cost = sum - (max + min);
        if (cost < k * range) {
            return sum - (k * range);
        } else {
            return sum;
        }
    }
}
