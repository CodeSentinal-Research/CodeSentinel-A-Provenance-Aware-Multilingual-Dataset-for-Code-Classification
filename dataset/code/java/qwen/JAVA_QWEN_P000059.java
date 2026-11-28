import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long prod = 1;
        if (N == 0) prod = 0;
        while (n > 0) {
            prod *= n % 10;
            n /= 10;
        }
        System.out.println(prod);
    }
}
