import java.util.*;
public class Solution {
    static final long MOD = 1000000007;
    static long modPow(long base, long exp, long mod) {
        if (exp == 0) return 1;
        long half = modPow(base, exp / 2, mod);
        long res = (half * half) % mod;
        if (exp % 2 != 0) res = (res * base) % mod;
        return res;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            long n = scanner.nextLong();
            long evenPos = (n + 1) / 2;
            long oddPos = n / 2;
            long ans = (modPow(5, evenPos, MOD) * modPow(4, oddPos, MOD)) % MOD;
            System.out.println(ans);
        }
    }
}