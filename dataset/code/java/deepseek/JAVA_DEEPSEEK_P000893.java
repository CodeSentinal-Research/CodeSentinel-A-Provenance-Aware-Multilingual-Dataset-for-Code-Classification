import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        List<Long> primeFactors = distinctPrimeFactors(n);
        for (long factor : primeFactors) {
            System.out.print(factor + " ");
        }
    }

    private static List<Long> distinctPrimeFactors(long n) {
        List<Long> factors = new ArrayList<>();
        while (n % 2 == 0) {
            factors.add(2L);
            n /= 2;
        }

        for (long i = 3; i <= Math.sqrt(n); i += 2) {
            while (n % i == 0) {
                factors.add(i);
                n /= i;
            }
       }

        if (n > 2) {
            factors.add(n);
        }

        return factors;
    }
}
