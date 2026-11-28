import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        int[][] matrix = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        System.out.println(maxHourglassSum(matrix));
    }

    private static int maxHourglassSum(int[][] matrix) {
        int maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < matrix.length - 2; i++) {
            for (int j = 0; j < matrix[0].length - 2; j++) {
                int sum = matrix[i][j] + matrix[i][j+1] + matrix[i][j+2] +
                          matrix[i+1][j+1] +
                          matrix[i+2][j] + matrix[i+2][j+1] + matrix[i+2][j+2];
                maxSum = Math.max(maxSum, sum);
           }
        }
        return maxSum;
    }
}
