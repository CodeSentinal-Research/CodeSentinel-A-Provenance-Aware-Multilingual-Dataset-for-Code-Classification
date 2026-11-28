import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int units = scanner.nextInt();
        double bill = 0;

        if (units <= 100) {
            bill = units * 1.20;
        } else if (units <= 300) {
            bill = 100 * 1.20 + (units - 100) * 2.00;
       } else if (units > 300) {
            bill = 100 * 1.20 + 200 * 2.00 + (units - 300) * 3.00;
        }

        System.out.printf("%.2f", bill);
    }
}
