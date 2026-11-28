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
            long r1 = sc.nextLong(), m1 = sc.nextLong();
            long r2 = sc.nextLong(), m2 = sc.nextLong();
            long[] res = extGcd(m1, m2);
            long g = res[0], p = res[1];
            if ((r2 - r1) % g != 0) {
                System.out.println("-1");
            } else {
                long mod = (m1 / g) * m2;
                long step = (r2 - r1) / g;
                long k = (p * step) % (m2 / g);
                long ans = (r1 + k * m1) % mod;
                System.out.println(((ans % mod + mod) % mod) + " " + mod);
            }
        }
        sc.close();
    }
}