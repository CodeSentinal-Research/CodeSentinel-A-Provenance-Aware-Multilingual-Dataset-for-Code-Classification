import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int r = scanner.nextInt();
        System.out.println(binomialCoefficient(n, r));
    }

    static int binomialCoefficient(int n, int r) {
        if (r == 0 || r == n) {
            return 1;
        } else {
            return binomialCoefficient(n - 1, r - 1) + binomialCoefficient(n - 1, r);
        }
    }
}
