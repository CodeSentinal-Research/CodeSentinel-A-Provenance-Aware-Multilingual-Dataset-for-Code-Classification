import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long m = sc.nextLong();
        
        long g = gcd(a, m);
        if(b % g != 0) {
            System.out.println(-1);
            return;
        }
        
        a /= g; b /= g; m /= g;
        long[] res = extendedGcd(a, m);
        long x = (res[0] * b % m + m) % m;
        System.out.println(x);
    }
    static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
    static long[] extendedGcd(long a, long b) {
        if(b == 0) return new long[]{1, 0};
        long[] res = extendedGcd(b, a % b);
        return new long[]{res[1], res[0] - (a / b) * res[1]};
    }
}
