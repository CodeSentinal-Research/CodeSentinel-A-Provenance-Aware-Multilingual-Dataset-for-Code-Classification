import java.util.Scanner;

public class Solution {
    private static long[] extGcd(long a, long b) {
        if (b == 0) return new long[]{a, 1, 0};
        long[] res = extGcd(b, a % b);
        long g = res[0], x1 = res[1], y1 = res[2];
        return new long[]{g, y1, x1 - (a / b) * y1};
    }

    public static long earliestTimestamp(long[] mods, long[] rems) {
        long a1 = rems[0], m1 = mods[0];
        for (int i = 1; i < mods.length; i++) {
            long a2 = rems[i], m2 = mods[i];
            long[] res = extGcd(m1, m2);
            long g = res[0], p = res[1];
            if ((a2 - a1) % g != 0) return -1;
            long mod = (m1 / g) * m2;
            long step = (a2 - a1) / g;
            long k = (p * step) % (m2 / g);
            a1 = (a1 + k * m1) % mod;
            m1 = mod;
        }
        return (a1 % m1 + m1) % m1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int k = sc.nextInt();
            long[] mods = new long[k];
            for (int i = 0; i < k; i++) mods[i] = sc.nextLong();
            long[] rems = new long[k];
            for (int i = 0; i < k; i++) rems[i] = sc.nextLong();
            System.out.println(earliestTimestamp(mods, rems));
        }
        sc.close();
    }
}