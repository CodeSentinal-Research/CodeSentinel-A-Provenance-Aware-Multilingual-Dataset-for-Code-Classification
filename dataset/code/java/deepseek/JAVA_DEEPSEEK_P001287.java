import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] sweetness = new int[N];
        for (int i = 0; i < N; i++) {
            sweetness[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(divideChocolate(sweetness, N, K));
    }

    private static int divideChocolate(int[] sweetness, int N, int K) {
        int low = 0, high = Integer.MAX_VALUE;
        while (low < high) {
            int mid = (low + high) / 2;
            if (canDivide(sweetness, N, K, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }

    private static boolean canDivide(int[] sweetness, int N, int K, int target) {
        int count = 0, sum = 0;
        for (int i = 0; i < N; i++) {
            sum += sweetness[i];
            if (sum >= target) {
                sum = 0;
                count++;
                if (count > K) {
                    return false;
                }
            }
        }
        return count <= K;
    }
}
