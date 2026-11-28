import java.util.*;
public class Main {
    static long MOD;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();
        MOD = sc.nextLong();
        
        long[] fact = new long[n+1];
        fact[0] = 1;
        for(int i=1; i<=n; i++) fact[i] = (fact[i-1] * i) % MOD;
        
        long denom = (fact[r] * fact[n-r]) % MOD;
        long invDenom = modInverse(denom, MOD);
        System.out.println((fact[n] * invDenom) % MOD);
    }
    static long modInverse(long a, long m) {
        return modPow(a, m - 2, m);
    }
    static long modPow(long base, long exp, long mod) {
        long res = 1;
        base %= mod;
        while(exp > 0) {
            if(exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
}
