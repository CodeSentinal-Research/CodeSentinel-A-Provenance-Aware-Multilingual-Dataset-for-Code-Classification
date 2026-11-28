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

        long[] prefixSum = new long[N + 1];
        for (int i = 0; i < N; i++) {
            prefixSum[i + 1] = prefixSum[i] + arr[i];
        }

        int Q = scanner.nextInt();
        for (int i = 0; i < Q; i++) {
            int L = scanner.nextInt();
            int R = scanner.nextInt();

            long sum = prefixSum[R] - prefixSum[L - 1];
            if (L > 1) {
                sum -= prefixSum[L - 1];
            }

            System.out.println(sum % K == 0 ? "YES" : "NO");
        }
    }
}
