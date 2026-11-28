import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }

        int Q = scanner.nextInt();
        for (int i = 0; i < Q; i++) {
            int L = scanner.nextInt();
            int R = scanner.nextInt();
            System.out.println(countEven(arr, L, R));
        }
    }

    private static int countEven(int[] arr, int L, int R) {
        if (L == 1) {
            return arr[R];
        }
        return arr[R] - arr[L - 1];
    }
}
