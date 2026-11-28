import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        int maxDiff = arr[K - 1] - arr[0];
        for (int i = 0; i < N - K + 1; i++) {
            int diff = arr[i + K - 1] - arr[i];
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        }
        System.out.println(maxDiff);
    }
}
