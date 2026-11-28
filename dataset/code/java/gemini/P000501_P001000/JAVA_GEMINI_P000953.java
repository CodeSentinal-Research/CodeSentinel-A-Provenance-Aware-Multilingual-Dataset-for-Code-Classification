import java.util.Scanner;

public class Solution {
    private static long phi(long n) {
        long res = n;
        for (long p = 2; p * p <= n; p++) {
            if (n % p == 0) {
                while (n % p == 0) n /= p;
                res -= res / p;
            }
        }
        if (n > 1) res -= res / n;
        return res;
    }

    private static long modPow(long base, long exp, long mod) {
        long res = 1;
        base %= mod;
        // Binary exponentiation: process exponent bits from LSB to MSB
        while (exp > 0) {
            // If current bit is set, multiply base into result
            if (exp % 2 == 1) res = (res * base) % mod;
            // Square the base for the next bit
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            long m = sc.nextLong();
            long p = phi(m);
            long exp = b % p;
            System.out.println(modPow(a, exp, m));
        }
        sc.close();
    }
}