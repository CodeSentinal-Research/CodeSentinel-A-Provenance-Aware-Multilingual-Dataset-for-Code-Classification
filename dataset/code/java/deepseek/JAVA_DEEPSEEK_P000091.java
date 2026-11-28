import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int r = scanner.nextInt();
        System.out.println(permutation(n, r));
    }

    public static int permutation(int n, int r) {
        int result = 1;
        for (int i = n; i > n - r; i--) {
            result *= i;
        }
        return result;
    }
}
