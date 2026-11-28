import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long largest = 0, smallest = 9;

        while (n > 0) {
            long digit = n % 10;
            largest = Math.max(largest, digit);
            smallest = Math.min(smallest, digit);
            n /= 10;
        }

        System.out.println(largest + " " + smallest);
    }
}