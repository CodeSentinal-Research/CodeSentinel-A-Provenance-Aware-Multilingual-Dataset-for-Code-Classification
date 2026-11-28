import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long m = sc.nextLong();
        long b = sc.nextLong();
        long n = sc.nextLong();
        
        long[] res = merge(a, m, b, n);
        if(res == null) System.out.println(-1);
        else System.out.println(res[0] + " " + res[1]);
    }
    static long[] merge(long r1, long m1, long r2, long m2) {
        long g = gcd(m1, m2);
        if((r2 - r1) % g != 0) return null;
        long lcm = m1 / g * m2;
        long diff = r2 - r1;
        long[] eg = extendedGcd(m1/g, m2/g);
        long k = ((diff / g) * eg[0]) % (m2/g);
        if(k < 0) k += m2/g;
        long x = (r1 + m1 * k) % lcm;
        if(x < 0) x += lcm;
        return new long[]{x, lcm};
    }
    static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
    static long[] extendedGcd(long a, long b) {
        if(b == 0) return new long[]{1, 0};
        long[] res = extendedGcd(b, a % b);
        return new long[]{res[1], res[0] - (a / b) * res[1]};
    }
}
