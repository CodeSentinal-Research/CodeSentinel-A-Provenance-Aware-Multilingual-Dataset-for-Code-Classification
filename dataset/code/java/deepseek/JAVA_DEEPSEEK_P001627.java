import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        long[] arr = new long[N];
        long[] prefixSum = new long[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextLong();
        }
        prefixSum[0] = arr[0];
        for (int i = 1; i < N; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }
        long count = 0;
        for (int i = 0; i < N; i++) {
            long remainder = prefixSum[i];
            if (remainder % K == 0) {
                count++;
            }
            if (i < N - 1) {
                remainder -= K;
                if (remainder % K == 0) {
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}
