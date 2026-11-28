import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();

        if (n >= 1 && n <= 16) {
            generateGrayCode(n);
        }
    }

    private static void generateGrayCode(int n) {
        if (n == 0) {
            return;
        }

        generateGrayCode(n - 1);

        for (int i = 0; i < n - 1; i++) {
            System.out.print("0");
        }
        System.out.println("0");

        for (int i = 0; i < n - 1; i++) {
            System.out.print("1");
        }
        System.out.println("1");

        generateGrayCode(n - 1);
    }
}
