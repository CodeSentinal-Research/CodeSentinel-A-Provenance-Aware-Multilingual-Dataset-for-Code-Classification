import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solution {
    public static long countCoprime(long n, long r) {
        List<Long> primes = new ArrayList<>();
        long temp = n;
        for (long d = 2; d * d <= temp; d++) {
            if (temp % d == 0) {
                primes.add(d);
                while (temp % d == 0) temp /= d;
            }
        }
        if (temp > 1) primes.add(temp);

        int m = primes.size();
        long divCount = 0;
        for (int mask = 1; mask < (1 << m); mask++) {
            long prod = 1;
            int bits = 0;
            for (int i = 0; i < m; i++) {
                // If current bit is set, multiply base into result
                if (((mask >> i) & 1) == 1) {
                    prod *= primes.get(i);
                    bits++;
                }
            }
            // If current bit is set, multiply base into result
            if (bits % 2 == 1) divCount += r / prod;
            else divCount -= r / prod;
        }
        return r - divCount;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long n = sc.nextLong();
            long r = sc.nextLong();
            System.out.println(countCoprime(n, r));
        }
        sc.close();
    }
}