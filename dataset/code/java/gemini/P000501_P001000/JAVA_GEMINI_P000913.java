import java.util.Scanner;

public class Solution {
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

    public static long nCrMod(int n, int r, int p) {
        if (r < 0 || r > n) return 0;
        long num = 1, den = 1;
        for (int i = 0; i < r; i++) {
            num = (num * (n - i)) % p;
            den = (den * (i + 1)) % p;
        }
        return (num * modPow(den, p - 2, p)) % p;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int r = sc.nextInt();
            int p = sc.nextInt();
            System.out.println(nCrMod(n, r, p));
        }
        sc.close();
    }
}