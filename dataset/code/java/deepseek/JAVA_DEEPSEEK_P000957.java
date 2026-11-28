import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long A = scanner.nextLong();
        long B = scanner.nextLong();
        long X = scanner.nextLong();
        long Y = scanner.nextLong();

        long gcd = gcd(Math.abs(A), Math.abs(B));
        A /= gcd;
        B /= gcd;

        System.out.println((A * X + B * Y) == gcd);
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
