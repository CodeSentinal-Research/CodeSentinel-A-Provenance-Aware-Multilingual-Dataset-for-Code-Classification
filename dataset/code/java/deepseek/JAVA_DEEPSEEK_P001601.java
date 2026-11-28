import java.util.Scanner;

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
            System.out.println(countZeros(arr, L, R));
        }

        scanner.close();
    }

    private static int countZeros(int[] arr, int L, int R) {
        if (L == 1 && R == arr.length) {
            return 0;
        }

        if (L == 1) {
            return arr[R - 1];
        }

        if (R == arr.length) {
            return arr[L - 1];
        }

        return arr[R - 1] - arr[L - 1] + 1;
    }
}
