import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        System.out.println(kthGrammar(N, K));
    }

    public static int kthGrammar(int N, int K) {
        if (N == 1) {
            return 0;
        }
        if (K % 2 == 0) {
            return kthGrammar(N - 1, K / 2) == 0 ? 1 : 0;
        } else {
            return kthGrammar(N - 1, (K + 1) / 2) == 0 ? 0 : 1;
        }
    }
}
