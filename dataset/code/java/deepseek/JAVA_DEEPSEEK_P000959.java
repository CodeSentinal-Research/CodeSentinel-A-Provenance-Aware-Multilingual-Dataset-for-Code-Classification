import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long A = scanner.nextLong();
        long B = scanner.nextLong();
        long C = scanner.nextLong();

        System.out.println(hasSolution(A, B, C) ? "true" : "false");
    }

    private static boolean hasSolution(long A, long B, long C) {
        if (B == 0) {
            return C == 0 || A == 0;
        }
        if (A == 0) {
            return C % B == 0;
        }
        if (C % A != 0) {
            return false;
        }
        return hasSolution(B, A % B, C % A);
    }
}
