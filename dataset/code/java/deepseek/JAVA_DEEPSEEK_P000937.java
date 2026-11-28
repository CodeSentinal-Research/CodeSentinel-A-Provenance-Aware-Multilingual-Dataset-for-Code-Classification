import java.util.Scanner;

public class Main {
    static int N;
    static long K;
    static long[][] A;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        K = scanner.nextLong();
        A = new long[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = scanner.nextLong();
            }
        }
        long[][] result = matrixPower(A, K);
        printMatrix(result);
    }

    private static long[][] matrixPower(long[][] A, long K) {
        long[][] result = new long[N][N];
        for (int i = 0; i < N; i++) {
            result[i][i] = 1;
        }
        while (K > 0) {
            if ((K & 1) == 1) {
                result = multiply(result, A);
            }
            A = multiply(A, A);
            K >>= 1;
        }
        return result;
    }

    private static long[][] multiply(long[][] A, long[][] B) {
        long[][] result = new long[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % 1000000007;
                }
            }
        }
        return result;
    }

    private static void printMatrix(long[][] matrix) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
