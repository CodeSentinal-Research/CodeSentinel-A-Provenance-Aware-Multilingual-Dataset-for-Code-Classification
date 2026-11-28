import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();

        printGray(n, 1);
    }

    private static void printGray(int n, int previous) {
        if (n == 0) {
            System.out.println(previous);
            return;
        }

        printGray(n - 1, previous);

        int current = 1 << (n - 1);
        if (previous != current) {
            System.out.println(current);
        }

        printGray(n - 1, current);
    }
}
