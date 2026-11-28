import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        scanner.close();

        if (n < 1 || n > Math.pow(10, 9)) {
            throw new IllegalArgumentException("Input out of range: " + n);
        }

        long sqrt = (long) Math.sqrt(n);
        if (sqrt * sqrt == n) {
            System.out.println("Perfect Square");
        } else {
            System.out.println("Not Perfect Square");
        }
    }
}
