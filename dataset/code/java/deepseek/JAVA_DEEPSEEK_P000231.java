import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] matrix = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        printSorted(matrix);
    }

    private static void printSorted(int[][] matrix) {
        int n = matrix.length;
        int[] sorted = new int[n * n];
        int k = 0;
        for (int[] row : matrix) {
            for (int num : row) {
                sorted[k++] = num;
            }
        }
        Arrays.sort(sorted);
        for (int num : sorted) {
            System.out.println(num);
        }
    }
}
