import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] arr = new long[n];
        long[] prefixSums = new long[n];
        long maxAbsPrefixSum = Long.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLong();
            if (i == 0) {
                prefixSums[i] = arr[i];
            } else {
                prefixSums[i] = prefixSums[i - 1] + arr[i];
            }
            maxAbsPrefixSum = Math.max(maxAbsPrefixSum, prefixSums[i]);
        }

        System.out.println(maxAbsPrefixSum);
    }
}
