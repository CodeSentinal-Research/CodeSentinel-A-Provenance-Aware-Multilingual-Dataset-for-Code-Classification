import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        System.out.println(minSum(A, K));
    }

    public static int minSum(int[] A, int K) {
        int minSum = Integer.MAX_VALUE;
        int windowSum = 0;
        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < A.length; windowEnd++) {
            windowSum += A[windowEnd];
            if (windowEnd >= K - 1) {
                minSum = Math.min(minSum, windowSum);
                windowSum -= A[windowStart];
                windowStart++;
            }
        }
        return minSum;
    }
}
