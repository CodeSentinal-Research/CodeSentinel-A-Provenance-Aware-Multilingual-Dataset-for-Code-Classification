import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long A = scanner.nextLong();
        long M = scanner.nextLong();
        System.out.println(modInverse(A, M));
    }

    static long modInverse(long A, long M) {
        long m0 = M;
        long x = 1;
        long y = 0;

        if (M == 1)
            return 0;

        while (A > 1) {
            long q = A / M;
            long t = M;

            M = A % M;
            A = t;
            t = y;

            y = x - q * y;
            x = t;
        }

        if (x < 0)
            x += m0;

        return x;
    }
}
