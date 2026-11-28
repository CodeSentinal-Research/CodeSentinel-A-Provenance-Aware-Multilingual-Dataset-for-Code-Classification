import java.util.Scanner;

public class Main {
    static int N, K;
    static int[] numbers;
    static boolean[] used;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        K = scanner.nextInt();
        numbers = new int[K];
        used = new boolean[N + 1];
        backtrack(0);
    }

    private static void backtrack(int at) {
        if (at == K) {
            for (int i = 0; i < K; i++) {
                System.out.print(numbers[i] + (i == K - 1 ? "\n" : " "));
            }
            return;
        }
        for (int i = 1; i <= N; i++) {
            if (!used[i]) {
                used[i] = true;
                numbers[at] = i;
                backtrack(at + 1);
                used[i] = false;
            }
        }
    }
}
