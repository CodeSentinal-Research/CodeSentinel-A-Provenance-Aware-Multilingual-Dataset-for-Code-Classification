import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] arr = new long[n];
        long[] prefixSum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLong();
        }
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            prefixSum[i + 1] = sum;
        }
        if (sum % 3 != 0) {
            System.out.println(0);
            return;
        }
        long target = sum / 3;
        int count = 0;
        if (prefixSum[n] % 3 == 0 && prefixSum[n] - target * 3 == 0) {
            count = 1;
            for (int i = 0; i < n; i++) {
                if (prefixSum[i] == target) {
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}
