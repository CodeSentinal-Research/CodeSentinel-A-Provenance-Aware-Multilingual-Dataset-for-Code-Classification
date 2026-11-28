import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] payments = new int[n];
        for (int i = 0; i < n; i++) {
            payments[i] = scanner.nextInt();
        }
        scanner.close();

        if (canProvideChange(payments)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    private static boolean canProvideChange(int[] payments) {
        int total = 0;
        for (int payment : payments) {
            total += payment;
        }
        return total % 5 == 0;
    }
}
