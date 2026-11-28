import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] arr = new long[n];
        long[] prefixSum = new long[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLong();
            sum += arr[i];
            prefixSum[i] = sum;
        }
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            if (prefixSum[i] < 0) {
                maxLength = Math.max(maxLength, i + 1);
            }
        }
        System.out.println(maxLength == 0 ? 0 : maxLength);
    }
}
