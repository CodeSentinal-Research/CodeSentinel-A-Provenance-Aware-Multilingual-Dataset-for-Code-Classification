import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solution {
    public static List<Long> distinctPrimeFactors(long n) {
        List<Long> factors = new ArrayList<>();
        for (long d = 2; d * d <= n; d++) {
            if (n % d == 0) {
                factors.add(d);
                while (n % d == 0) n /= d;
            }
        }
        if (n > 1) factors.add(n);
        return factors;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long n = sc.nextLong();
            List<Long> res = distinctPrimeFactors(n);
            for (int i = 0; i < res.size(); i++) {
                System.out.print(res.get(i) + (i == res.size() - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}