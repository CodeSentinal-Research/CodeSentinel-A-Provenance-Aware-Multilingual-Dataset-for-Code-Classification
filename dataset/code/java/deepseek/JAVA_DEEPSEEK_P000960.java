import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long A = scanner.nextLong();
        long B = scanner.nextLong();
        long C = scanner.nextLong();
        scanner.close();

        if (C % gcd(A, B) != 0) {
            System.out.println(-1);
            return;
        }

        long[] result = extendedEuclidean(A, B);
        System.out.println(result[0] * (C / result[2]) + " " + result[1] * (C / result[2]));
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
        if (b == 0) {
            return new long[]{1, 0, a};
        }
        long[] result = extendedEuclidean(b, a % b);
        return new long[]{result[1], result[0] - (a / b) * result[1], result[2]};
    }
}
