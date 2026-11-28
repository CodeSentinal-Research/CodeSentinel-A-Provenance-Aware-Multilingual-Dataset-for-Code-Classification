import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long product = 1;
        while (n > 0) {
            long digit = n % 10;
            if (digit != 0) {
                product *= digit;
            } else {
                product = 0;
                break;
            }
            n /= 10;
        }
        System.out.println(product);
    }
}