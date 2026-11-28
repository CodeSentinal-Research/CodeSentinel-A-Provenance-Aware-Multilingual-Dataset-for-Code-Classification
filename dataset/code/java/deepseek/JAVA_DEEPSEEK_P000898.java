import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long numerator = scanner.nextLong();
        long denominator = scanner.nextLong();

        long gcd = gcd(numerator, denominator);

        numerator /= gcd;
        denominator /= gcd;

        System.out.println(numerator + " " + denominator);
    }

    private static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
}
