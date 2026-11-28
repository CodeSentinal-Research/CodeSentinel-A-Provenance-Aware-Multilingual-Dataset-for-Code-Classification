import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long product = 1;
        while (n > 0) {
            product *= n % 10;
            n /= 10;
        }
        System.out.println(product);
    }
}