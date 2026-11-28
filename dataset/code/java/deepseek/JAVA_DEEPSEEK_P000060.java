import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int count = 0;
        while (n > 0) {
            int digit = n % 10;
            if (digit % 2 == 0) {
                count++;
            }
            n = n / 10;
        }
        System.out.println(count);
    }
}
