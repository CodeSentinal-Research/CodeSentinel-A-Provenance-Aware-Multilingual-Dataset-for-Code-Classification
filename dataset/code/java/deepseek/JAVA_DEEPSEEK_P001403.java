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
            System.out.println(canFormArithmeticSequence(arr, L, R) ? "YES" : "NO");
        }

        scanner.close();
    }

    private static boolean canFormArithmeticSequence(int[] arr, int L, int R) {
        int diff = arr[R] - arr[L];
        if (diff == 0) {
            return arr.length == R - L + 1;
        }
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] - arr[L] == diff) {
                return true;
            }
        }
        return false;
    }
}
