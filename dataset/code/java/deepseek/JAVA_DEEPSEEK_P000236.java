import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[][] mat = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                mat[i][j] = scanner.nextInt();
            }
        }
        int maxDiff = Integer.MIN_VALUE;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = i + 1; k < N; k++) {
                    for (int l = j + 1; l < N; l++) {
                        int diff = mat[k][l] - mat[i][j];
                        if (diff > maxDiff) {
                            maxDiff = diff;
                        }
                    }
                }
            }
        }
        System.out.println(maxDiff);
    }
}
