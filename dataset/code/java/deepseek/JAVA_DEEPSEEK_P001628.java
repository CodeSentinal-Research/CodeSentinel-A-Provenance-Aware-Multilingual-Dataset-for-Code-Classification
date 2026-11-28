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
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            if (prefixSum[i] > 0) {
                maxLength = i + 1;
                break;
            }
        }
        System.out.println(maxLength == 0 ? 0 : maxLength);
    }
}
