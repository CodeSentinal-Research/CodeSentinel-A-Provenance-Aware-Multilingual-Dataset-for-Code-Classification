import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String A = scanner.next();
        String B = scanner.next();

        BigInteger a = new BigInteger(A, 2);
        BigInteger b = new BigInteger(B, 2);

        BigInteger sum = a.add(b);

        System.out.println(sum.toString(2));
    }
}
