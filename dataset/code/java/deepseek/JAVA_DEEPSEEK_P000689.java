import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        System.out.println(productOfDigits(n));
    }

    public static long productOfDigits(long n) {
        if (n == 0) {
            return 1;
        }
        return n % 10 * productOfDigits(n / 10);
    }
}
