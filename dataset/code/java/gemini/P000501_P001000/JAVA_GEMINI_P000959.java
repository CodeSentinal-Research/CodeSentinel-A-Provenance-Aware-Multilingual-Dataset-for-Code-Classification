import java.util.Scanner;

public class Solution {
    private static long[] extGcd(long a, long b) {
        if (b == 0) return new long[]{a, 1, 0};
        long[] res = extGcd(b, a % b);
        long g = res[0], x1 = res[1], y1 = res[2];
        return new long[]{g, y1, x1 - (a / b) * y1};
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            long c = sc.nextLong();
            long[] res = extGcd(a, b);
            long g = res[0], x = res[1], y = res[2];
            if (c % g != 0) {
                System.out.println("NO");
            } else {
                long factor = c / g;
                System.out.println("YES\n" + (x * factor) + " " + (y * factor));
            }
        }
        sc.close();
    }
}