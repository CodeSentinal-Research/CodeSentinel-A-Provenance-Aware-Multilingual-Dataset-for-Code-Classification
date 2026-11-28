import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        System.out.println(isDivisibleBy9(n));
    }

    private static boolean isDivisibleBy9(long n) {
        if (n < 0) {
            n = -n;
        }
        while (n != 0) {
            long digit = n % 10;
            n /= 10;
            n += digit;
        }
        return n % 9 == 0;
    }
}
