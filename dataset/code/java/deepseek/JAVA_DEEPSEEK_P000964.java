import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        BigInteger[] remainder = new BigInteger[n];
        BigInteger[] modulus = new BigInteger[n];
        for (int i = 0; i < n; i++) {
            remainder[i] = scanner.nextBigInteger();
        }
        for (int i = 0; i < n; i++) {
            modulus[i] = scanner.nextBigInteger();
       }
       
        BigInteger result = solve(n, remainder, modulus);
        System.out.println(result);
    }

    private static BigInteger solve(int n, BigInteger[] remainder, BigInteger[] modulus) {
        BigInteger result = BigInteger.ZERO;
        BigInteger product = BigInteger.ONE;
        for (int i = 0; i < n; i++) {
            product = product.multiply(modulus[i]);
        }
        for (int i = 0; i < n; i++) {
            BigInteger pp = product.divide(modulus[i]);
            BigInteger inv = pp.modInverse(modulus[i]);
            result = result.add(remainder[i].multiply(pp).multiply(inv));
        }
        return result.mod(product);
    }
}
