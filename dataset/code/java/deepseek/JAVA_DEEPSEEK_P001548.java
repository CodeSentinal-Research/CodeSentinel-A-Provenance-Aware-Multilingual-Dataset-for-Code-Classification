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
        long maxProduct = Long.MIN_VALUE;
        long windowProduct = 1;
        for (int i = 0; i < K; i++) {
            windowProduct *= arr[i];
        }
        maxProduct = Math.max(maxProduct, windowProduct);
        for (int i = K; i < N; i++) {
            windowProduct /= arr[i - K];
            windowProduct *= arr[i];
            maxProduct = Math.max(maxProduct, windowProduct);
        }
        System.out.println(maxProduct);
    }
}
