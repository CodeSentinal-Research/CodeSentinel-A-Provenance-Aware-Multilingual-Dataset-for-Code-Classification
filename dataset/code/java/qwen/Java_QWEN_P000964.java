import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] rem = new long[n];
        long[] mod = new long[n];
        for(int i=0; i<n; i++) rem[i] = sc.nextLong();
        for(int i=0; i<n; i++) mod[i] = sc.nextLong();
        
        long x = rem[0];
        long m = mod[0];
        for(int i=1; i<n; i++) {
            // Merge x ≡ rem[i] (mod mod[i]) with current x ≡ x (mod m)
            // Using CRT merge logic
            long[] res = merge(x, m, rem[i], mod[i]);
            if(res == null) { System.out.println(-1); return; }
            x = res[0];
            m = res[1];
        }
        System.out.println(x);
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
