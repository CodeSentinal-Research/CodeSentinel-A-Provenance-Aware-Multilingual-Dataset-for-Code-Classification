import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long base = sc.nextLong();
        long exp = sc.nextLong();
        long mod = sc.nextLong();
        System.out.println(modPow(base, exp, mod));
    }
    static long modPow(long base, long exp, long mod) {
        if(exp == 0) return 1;
        long half = modPow(base, exp / 2, mod);
        long res = (half * half) % mod;
        if(exp % 2 == 1) res = (res * base) % mod;
        return res;
    }
}
