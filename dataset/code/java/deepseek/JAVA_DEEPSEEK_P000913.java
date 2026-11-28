import java.util.Scanner;

public class Main {
    static int mod = 1000000007;

    static long power(long x, long y) {
        long res = 1;
        x = x % mod;
        while (y > 0) {
            if ((y & 1) == 1)
                res = (res * x) % mod;
            y = y >> 1;
            x = (x * x) % mod;
        }
        return res;
   }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int r = scanner.nextInt();
        int p = scanner.nextInt();
        mod = p;
        long numerator = 1;
        for (int i = n; i <= n-r+1; i++) {
            numerator = (numerator * i) % p;
        }
        long denominator = 1;
        for (int i = 1; i <= r; i++) {
            denominator = (denominator * i) % p;
        }
    }
}