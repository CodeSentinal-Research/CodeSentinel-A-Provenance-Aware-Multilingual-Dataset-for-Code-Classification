import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        long[] marbles = new long[N];
        for (int i = 0; i < N; i++) {
            marbles[i] = scanner.nextLong();
        }
        scanner.close();
        Arrays.sort(marbles);
        long minScore = Long.MAX_VALUE;
        long maxScore = Long.MIN_VALUE;
        for (int i = 0; i < N - K + 1; i++) {
            long score = marbles[i + K - 1] - marbles[i];
            minScore = Math.min(minScore, score);
            maxScore = Math.max(maxScore, score);
        }
        System.out.println(maxScore - minScore);
    }
}
