import java.util.Scanner;
import java.util.TreeSet;

public class Main {
    private static final String SPACE = " ";
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int K = scanner.nextInt();
        int[][] matrix = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        scanner.close();

        long maxSum = 0;
        for (int left = 0; left < M; left++) {
            int[] prefixSum = new int[N];
            for (int right = left; right < M; right++) {
                for (int i = 0; i < N; i++) {
                    prefixSum[i] += matrix[i][right];
                }
                TreeSet<Integer> set = new TreeSet<>();
                set.add(prefixSum[0]);
                for (int i = 1; i < N; i++) {
                    prefixSum[i] += prefixSum[i - 1];
                    set.add(prefixSum[i]);
                }
                long sum = 0;
                for (int i = 0; i <= K && set.size() > 0; i++) {
                    Integer ceiling = set.ceiling(i);
                    if (ceiling != null) {
                        sum += (ceiling - i);
                    }
                    set.remove(i);
                }
                maxSum = Math.max(maxSum, sum);
            }
        }
        System.out.println(maxSum);
    }
}
