import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextBigInteger()) {
            BigInteger a = scanner.nextBigInteger();
            if (scanner.hasNextBigInteger()) {
                BigInteger b = scanner.nextBigInteger();
                System.out.println(a.multiply(b));
            }
        }
        scanner.close();
    }
}