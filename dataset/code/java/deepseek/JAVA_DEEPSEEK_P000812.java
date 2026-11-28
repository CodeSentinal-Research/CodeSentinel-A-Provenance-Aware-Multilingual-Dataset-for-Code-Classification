import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        System.out.println(isPerfectSquare(num));
    }

    private static boolean isPerfectSquare(int num) {
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
           }
            if (squared < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
}
