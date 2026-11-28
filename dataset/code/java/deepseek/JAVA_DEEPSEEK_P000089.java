import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(integerSquareRoot(n));
    }

    private static int integerSquareRoot(int n) {
        if (n == 0 || n == 1) {
            return n;
        }

        int start = 0;
        int end = n;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (mid * mid == n) {
                return mid;
           }
            if (mid * mid < n) {
                start = mid + 1;
                continue;
            }
            end = mid - 1;
        }

        return start - 1;
    }
}
