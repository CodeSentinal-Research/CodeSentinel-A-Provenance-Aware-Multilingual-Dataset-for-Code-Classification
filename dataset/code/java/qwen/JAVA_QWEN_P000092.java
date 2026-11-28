import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a = sc.nextDouble();
        double d = sc.nextDouble();
        int n = sc.nextInt();
        System.out.println((n / 2.0) * (2 * a + (n - 1) * d));
    }
}
