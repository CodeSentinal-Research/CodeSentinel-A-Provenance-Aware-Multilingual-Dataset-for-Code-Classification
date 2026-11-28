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
        long[] prefixSum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = (prefixSum[i] + arr[i]) % k;
        }
        long count = 0;
        for (int i = 0; i < n; i++) {
            if (prefixSum[i + 1] == 0) {
                count++;
            }
        }
        System.out.println(count);
    }
}
