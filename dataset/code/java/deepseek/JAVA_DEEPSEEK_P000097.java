import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        while (n != 0) {
            if (n % 10 == 0) {
                System.out.println("Duck");
                return;
            }
            n /= 10;
        }
        System.out.println("Not Duck");
    }
}
