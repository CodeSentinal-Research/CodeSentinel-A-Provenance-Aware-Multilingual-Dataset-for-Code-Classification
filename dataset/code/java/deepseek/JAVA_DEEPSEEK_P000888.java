import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        System.out.println(isAutomorphic(n));
    }

    private static boolean isAutomorphic(long n) {
        long square = n * n;
        while (n > 0) {
            if (n % 10 != square % 10) {
                return false;
            }
            n /= 10;
            square /= 10;
        }
        return true;
    }
}