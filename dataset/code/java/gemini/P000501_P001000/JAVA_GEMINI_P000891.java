import java.util.Scanner;

public class Solution {
    private static boolean isPrime(long n) {
        if (n < 2) return false;
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    public static long nextPrime(long n) {
        long cand = n + 1;
        while (!isPrime(cand)) {
            cand++;
        }
        return cand;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long n = sc.nextLong();
            System.out.println(nextPrime(n));
        }
        sc.close();
    }
}