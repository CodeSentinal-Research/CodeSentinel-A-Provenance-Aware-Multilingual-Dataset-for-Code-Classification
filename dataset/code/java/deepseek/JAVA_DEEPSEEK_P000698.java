import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long base = scanner.nextLong();
        long exponent = scanner.nextLong();
        long mod = scanner.nextLong();
        System.out.println(fastModularExponentiation(base, exponent, mod));
    }

    private static long fastModularExponentiation(long base, long exponent, long mod) {
        if (exponent == 0) {
            return 1;
        }
        long temp = fastModularExponentiation(base, exponent / 2, mod);
        if (exponent % 2 == 0) {
            return (temp * temp) % mod;
       } else {
            return (((temp * temp) % mod) * base) % mod;
        }
    }
}
