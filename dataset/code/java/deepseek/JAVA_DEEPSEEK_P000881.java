import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        System.out.println(countDigits(n));
    }

    private static int countDigits(long n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            n = -n;
       }
        return (int) Math.log10(n) + 1;
    }
}
