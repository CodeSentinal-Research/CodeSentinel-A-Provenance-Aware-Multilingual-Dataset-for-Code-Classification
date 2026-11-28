import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();

        int[][] matrix = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        int Q = scanner.nextInt();

        for (int i = 0; i < Q; i++) {
            int r1 = scanner.nextInt() - 1;
            int c1 = scanner.nextInt() - 1;
            int r2 = scanner.nextInt() - 1;
            int c2 = scanner.nextInt() - 1;

            int sum = 0;

            for (int row = r1; row <= r2; row++) {
                for (int col = c1; col <= c2; col++) {
                    sum += matrix[row][col];
                }
            }

            System.out.println(sum);
        }
    }
}
