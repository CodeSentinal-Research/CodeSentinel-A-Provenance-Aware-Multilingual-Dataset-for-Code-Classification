import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String number = scanner.next();
        int baseA = scanner.nextInt();
        int baseB = scanner.nextInt();

        BigInteger bigInt = new BigInteger(number, baseA);
        String result = bigInt.toString(baseB);

        System.out.println(result);
    }
}
