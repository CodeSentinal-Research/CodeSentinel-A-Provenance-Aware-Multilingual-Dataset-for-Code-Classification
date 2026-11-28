import java.util.*;
public class Main {
    static long MOD = 1000000007;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long evenPos = (n + 1) / 2;
        long oddPos = n / 2;
        long res = (modPow(5, evenPos) * modPow(4, oddPos)) % MOD;
        System.out.println(res);
    }
    static long modPow(long base, long exp) {
        if(exp == 0) return 1;
        long half = modPow(base, exp / 2);
        long res = (half * half) % MOD;
        if(exp % 2 == 1) res = (res * base) % MOD;
        return res;
    }
}
