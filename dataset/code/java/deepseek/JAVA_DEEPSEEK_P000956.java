import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long A = scanner.nextLong();
        long B = scanner.nextLong();
        long M = scanner.nextLong();

        long gcd = gcd(A, M);
        if (B % gcd != 0) {
            System.out.println(-1);
            return;
        }

        A /= gcd;
        B /= gcd;
        M /= gcd;

        long result = pow(A, M - 2, M) * B % M;
        System.out.println(result);
    }

    private static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    private static long pow(long a, long b, long m) {
        if (b == 0) {
            return 1;
        }
        long p = pow(a, b / 2, m);
        p = p * p % m;
        if ((b & 1) != 0) {
            p = p * a % m;
        }
        return p;
    }
}
