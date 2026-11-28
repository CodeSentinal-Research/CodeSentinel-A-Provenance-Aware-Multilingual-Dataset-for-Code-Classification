import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int d = scanner.nextInt();
        int n = scanner.nextInt();

        int sum = (n / 2) * (2 * a + (n - 1) * d);
        System.out.println(sum);
    }
}
