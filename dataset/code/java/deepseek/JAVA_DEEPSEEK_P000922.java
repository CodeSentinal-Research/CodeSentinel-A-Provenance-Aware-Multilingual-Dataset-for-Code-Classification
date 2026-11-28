import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long L = scanner.nextLong();
        long R = scanner.nextLong();
        long sum = 0;
        for (long i = L; i <= R; i++) {
            sum += sumOfDigits(i);
        }
        System.out.println(sum);
    }

    private static long sumOfDigits(long num) {
        long sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}
