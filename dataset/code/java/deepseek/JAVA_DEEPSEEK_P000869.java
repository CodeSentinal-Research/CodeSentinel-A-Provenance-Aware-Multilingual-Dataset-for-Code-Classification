import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int dividend = scanner.nextInt();
        int divisor = scanner.nextInt();
        System.out.println(divide(dividend, divisor));
    }

    public static int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        int a = Math.abs(dividend);
        int b = Math.abs(divisor);
        int res = 0;
        while (a - b >= 0) {
            int x = 0;
            while (a - (b << x) >= 0) {
                x++;
            }
            res += (1 << (x - 1));
            a -= (b << (x - 1));
        }
        return (dividend > 0 == divisor > 0) ? res : -res;
    }
}
