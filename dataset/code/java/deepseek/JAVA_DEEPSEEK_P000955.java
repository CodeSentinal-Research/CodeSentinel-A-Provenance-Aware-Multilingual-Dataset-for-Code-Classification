import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long a = scanner.nextLong();
        long m = scanner.nextLong();
        long gcd = extendedEuclideanAlgorithm(a, m);
        if (gcd != 1) {
            System.out.println(-1);
        } else {
            long result = (a % m + m) % m;
            System.out.println(result);
        }
    }

    private static long extendedEuclideanAlgorithm(long a, long b) {
        if (b == 0) {
            return a;
        } else {
            return extendedEuclideanAlgorithm(b, a % b);
        }
    }
}
