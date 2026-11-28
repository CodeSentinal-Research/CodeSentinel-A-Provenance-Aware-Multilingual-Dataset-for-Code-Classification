import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int r = scanner.nextInt();
        System.out.println(permutation(n, r));
    }

    static long permutation(int n, int r) {
        long p = 1;
        for (int i = 0; i < r; i++) {
            p *= n - i;
        }
        return p;
    }
}
