import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int low = scanner.nextInt();
        int high = scanner.nextInt();

        for (int i = low; i <= high; i++) {
            if (isSequential(i)) {
                System.out.println(i);
            }
        }
    }

    private static boolean isSequential(int n) {
        String str = String.valueOf(n);
        for (int i = 0; i < str.length() - 1; i++) {
            if (str.charAt(i + 1) - str.charAt(i) != 1) {
                return false;
            }
        }
        return true;
    }
}
