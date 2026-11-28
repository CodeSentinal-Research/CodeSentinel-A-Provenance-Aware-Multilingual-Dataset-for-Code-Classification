import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        System.out.println(catalan(N));
    }

    private static long catalan(int N) {
        long[] catalan = new long[N + 1];
        catalan[0] = 1;
        catalan[1] = 1;

        for(int i = 2; i <= N; i++) {
            catalan[i] = 0;
            for(int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }

        return catalan[N];
    }
}
