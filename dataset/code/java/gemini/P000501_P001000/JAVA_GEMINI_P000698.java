import java.util.*;
public class Solution {
    static long modPowRec(long base, long exp, long mod) {
        if (exp == 0) return 1 % mod;
        long half = modPowRec(base, exp / 2, mod);
        long res = (half * half) % mod;
        if (exp % 2 != 0) res = (res * (base % mod)) % mod;
        return res;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            long base = scanner.nextLong(), exp = scanner.nextLong(), mod = scanner.nextLong();
            System.out.println(modPowRec(base, exp, mod));
        }
    }
}