import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        System.out.println(countDigits(n));
    }

    public static int countDigits(long n) {
        if (n == 0) {
            return 0;
        } else {
            return 1 + countDigits(n / 10);
        }
    }
}
