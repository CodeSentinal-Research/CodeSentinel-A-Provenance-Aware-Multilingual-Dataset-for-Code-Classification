import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long l = scanner.nextLong();
        long r = scanner.nextLong();
        System.out.println(countCoprimes(n, l, r));
    }

    private static long countCoprimes(long n, long l, long r) {
        long count = 0;
        for (long i = l; i <= r; i++) {
            if (gcd(n, i) == 1) {
                count++;
            }
        }
        return count;
    }

    private static long gcd(long a, long b) {
        while (b > 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
