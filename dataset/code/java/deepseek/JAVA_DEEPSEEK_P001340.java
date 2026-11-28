import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] cookies = new int[N];
        for (int i = 0; i < N; i++) {
            cookies[i] = scanner.nextInt();
        }
        Arrays.sort(cookies);
        System.out.println(minUnfairness(cookies, K));
    }

    private static int minUnfairness(int[] cookies, int K) {
        int n = cookies.length;
        int[] prefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + cookies[i];
        }
        int minUnfairness = Integer.MAX_VALUE;
        for (int i = 0; i < n - K + 1; i++) {
            int left = prefixSum[i + K] - prefixSum[i];
            int right = prefixSum[n] - prefixSum[i + K];
            minUnfairness = Math.min(minUnfairness, Math.max(left, right));
        }
        return minUnfairness;
    }
}
