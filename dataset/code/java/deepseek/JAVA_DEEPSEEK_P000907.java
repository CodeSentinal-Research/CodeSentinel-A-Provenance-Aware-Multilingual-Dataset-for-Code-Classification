import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long A = scanner.nextLong();
        long B = scanner.nextLong();
        long M = scanner.nextLong();
        System.out.println(fastModularExponentiation(A, B, M));
    }

    private static long fastModularExponentiation(long A, long B, long M) {
        if (B == 0) {
            return 1;
        }
        long temp = fastModularExponentiation(A, B / 2, M);
        if (B % 2 == 0) {
            return (temp * temp) % M;
       } else {
            return ((A % M) * ((temp * temp) % M)) % M;
        }
    }
}
