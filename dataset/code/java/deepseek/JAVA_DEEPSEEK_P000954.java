import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        long[] result = extendedEuclidean(a, b);
        System.out.println(result[0] + " " + result[1] + " " + result[2]);
    }

    private static long[] extendedEuclidean(long a, long b) {
        if (b == 0) {
            return new long[]{1, 0, a};
        }
        long[] result = extendedEuclidean(b, a % b);
        long temp = result[0];
        result[0] = result[1];
        result[1] = temp - (a / b) * result[1];
        return result;
    }
}
