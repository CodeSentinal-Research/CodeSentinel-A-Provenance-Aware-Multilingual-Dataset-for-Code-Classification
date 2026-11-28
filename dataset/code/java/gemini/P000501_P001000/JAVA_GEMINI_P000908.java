import java.util.Scanner;

public class Solution {
    private static long[] extGcd(long a, long b) {
        if (b == 0) return new long[]{a, 1, 0};
        long[] res = extGcd(b, a % b);
        long g = res[0], x1 = res[1], y1 = res[2];
        long x = y1;
        long y = x1 - (a / b) * y1;
        return new long[]{g, x, y};
    }

    public static long modInverse(long a, long m) {
        long[] res = extGcd(a, m);
        if (res[0] != 1) return -1;
        return (res[1] % m + m) % m;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long a = sc.nextLong();
            long m = sc.nextLong();
            System.out.println(modInverse(a, m));
        }
        sc.close();
    }
}