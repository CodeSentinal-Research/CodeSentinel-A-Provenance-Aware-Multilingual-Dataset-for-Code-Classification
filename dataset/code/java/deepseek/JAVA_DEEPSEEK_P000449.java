import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        scanner.close();

        if (isPerfectSquare(n)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    private static boolean isPerfectSquare(long num) {
        if (num < 2) {
            return num >= 0;
        }

        long left = 2;
        long right = num / 2;

        while (left <= right) {
            long mid = (left + right) / 2;
            long squared = mid * mid;

            if (squared == num) {
                return true;
            } else if (squared < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
}
