import java.util.Scanner;

public class Solution {
    public static long modPow(long base, long exp, long mod) {
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
            long base = sc.nextLong();
            long exp = sc.nextLong();
            long mod = sc.nextLong();
            System.out.println(modPow(base, exp, mod));
        }
        sc.close();
    }
}