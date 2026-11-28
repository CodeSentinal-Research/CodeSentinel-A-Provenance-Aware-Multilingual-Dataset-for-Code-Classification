import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        long x = 0, y = 1;
        if (b == 1) {
            System.out.println(1 + " " + 0);
            return;
        }
        while (a > 0) {
            long q = b / a;
            long r = b % a;
            long x_ = x - q * y;
            long y_ = y - q * x;
            b = a;
            a = r;
            x = x_;
            y = y_;
        }
        System.out.println(y + " " + (x + y));
    }
}
