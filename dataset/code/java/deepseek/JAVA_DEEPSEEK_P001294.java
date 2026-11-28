import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] arr = new long[n];
        long[] prefixSum = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLong();
        }
        scanner.close();

        prefixSum[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }

        long maxPrefixSum = 0;
        for (int i = 0; i < n; i++) {
            maxPrefixSum = Math.max(maxPrefixSum, prefixSum[i]);
        }

        System.out.println(maxPrefixSum);
    }
}
