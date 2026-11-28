import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        int Q = scanner.nextInt();
        for (int i = 0; i < Q; i++) {
            int L = scanner.nextInt();
            int R = scanner.nextInt();
            int X = scanner.nextInt();

            int count = 0;
            for (int j = L; j <= R; j++) {
                if (A[j] == X) {
                    count++;
                }
            }

            System.out.println(count);
        }

        scanner.close();
    }
}
