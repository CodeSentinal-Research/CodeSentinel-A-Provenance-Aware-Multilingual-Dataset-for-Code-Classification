import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long A = scanner.nextLong();
        long M = scanner.nextLong();
        long B = scanner.nextLong();
        long N = scanner.nextLong();

        long gcd = gcd(M, N);
        if ((B - A) % gcd != 0 || (B - A) / gcd < 0) {
            System.out.println(-1);
            return;
        }

        long x = (B - A) / gcd;
        long m = M / gcd;
        long n = N / gcd;

        long[] result = extendedEuclidean(m, n);
        long y = result[0];
        long z = result[1];

        long solution = (x * y * m + x * z * n) % lcm(M, N);
        System.out.println(solution < 0 ? solution + lcm(M, N) : solution);
    }

    private static long gcd(long a, long b) {
        while (b > 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    private static long[] extendedEuclidean(long a, long b) {
        if (b == 0) return new long[]{1, 0};
        long[] temp = extendedEuclidean(b, a % b);
        return new long[]{temp[1], temp[0] - (a / b) * temp[1]};
    }

    private static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
}
