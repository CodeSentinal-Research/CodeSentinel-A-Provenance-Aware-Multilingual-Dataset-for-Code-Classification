import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger A = scanner.nextBigInteger();
        BigInteger N = scanner.nextBigInteger();
        System.out.println(A.modPow(phi(N), N));
    }

    private static BigInteger phi(BigInteger N) {
        BigInteger result = N;
        for (BigInteger i = BigInteger.TWO; i.compareTo(N) <= 0; i = i.add(BigInteger.ONE)) {
            if (N.mod(i).equals(BigInteger.ZERO)) {
                result = result.subtract(result.divide(i));
                while (N.mod(i).equals(BigInteger.ZERO)) {
                    N = N.divide(i);
                }
            }
        }
        if (N.compareTo(BigInteger.ONE) > 0) {
            result = result.subtract(result.divide(N));
        }
        return result;
    }
}
