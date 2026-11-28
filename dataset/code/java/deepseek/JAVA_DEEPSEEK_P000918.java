import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(factorial(n));
    }

    private static int factorial(int n) {
        int fact = 1;
        for(int i = 1; i <= n; ++i) {
            fact *= i;
        }
        return fact;
    }
}
