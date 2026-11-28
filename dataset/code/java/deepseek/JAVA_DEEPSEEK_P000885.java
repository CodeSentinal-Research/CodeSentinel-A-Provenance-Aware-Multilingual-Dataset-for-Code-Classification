import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        System.out.println(isArmstrong(n));
    }

    private static boolean isArmstrong(long n) {
        long temp = n;
        long sum = 0;
        int digits = 0;
        while (temp > 0) {
            temp /= 10;
            digits++;
        }
        temp = n;
        while (temp > 0) {
            long digit = temp % 10;
            sum += Math.pow(digit, digits);
            temp /= 10;
        }
        return sum == n;
    }
}
