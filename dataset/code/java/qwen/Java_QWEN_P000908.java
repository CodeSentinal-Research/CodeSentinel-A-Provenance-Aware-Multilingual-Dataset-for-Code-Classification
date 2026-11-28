import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long m = sc.nextLong();
        
        if(gcd(a, m) != 1) {
            System.out.println(-1);
            return;
        }
        
        // Extended Euclidean Algorithm
        long[] res = extendedGcd(a, m);
        long x = res[0];
        System.out.println((x % m + m) % m);
    }
    static long gcd(long a, long b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    static long[] extendedGcd(long a, long b) {
        if(b == 0) return new long[]{1, 0};
        long[] res = extendedGcd(b, a % b);
        long x1 = res[0], y1 = res[1];
        return new long[]{y1, x1 - (a / b) * y1};
    }
}
