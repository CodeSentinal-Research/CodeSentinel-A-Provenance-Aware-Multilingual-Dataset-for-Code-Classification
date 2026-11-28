import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        System.out.println(isHarshad(n));
    }

    private static boolean isHarshad(long n) {
        long temp = n;
        long sum = 0;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        return n % sum == 0;
    }
}
