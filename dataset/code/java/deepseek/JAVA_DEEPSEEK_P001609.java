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
        prefixSum[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }
        long count = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (prefixSum[n - 1] - prefixSum[i] == 0) {
                    count++;
                }
            } else if (i == n - 1) {
                if (prefixSum[i - 1] == 0) {
                    count++;
                }
            } else {
                if (prefixSum[i - 1] == prefixSum[n - 1] - prefixSum[i]) {
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}
