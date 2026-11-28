import java.util.Scanner;

public class Main {
    private static final long MOD = 1000000007;
    private static int N, Q, L, R;
    private static long[] A, XOR;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        A = new long[N + 1];
        XOR = new long[N + 1];
        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextLong();
            XOR[i] = XOR[i - 1] ^ A[i];
        }
        Q = scanner.nextInt();
        for (int i = 0; i < Q; i++) {
            L = scanner.nextInt();
            R = scanner.nextInt();
            System.out.println(XOR[R] ^ (L - 1 < 0 ? 0 : XOR[L - 1]));
        }
    }
}
