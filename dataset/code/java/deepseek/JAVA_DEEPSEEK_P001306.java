import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        long[] sizes = new long[N];
        long[] prefixSums = new long[N + 1];
        for (int i = 0; i < N; i++) {
            sizes[i] = scanner.nextLong();
        }
        scanner.close();
        for (int i = 0; i < N; i++) {
            prefixSums[i + 1] = prefixSums[i] + sizes[i];
        }
        long minCost = Long.MAX_VALUE;
        for (int i = 0; i < N - 1; i++) {
            minCost = Math.min(minCost, Math.abs(prefixSums[i + 1] - prefixSums[i]));
        }
        System.out.println(minCost);
    }
}
