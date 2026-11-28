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
        System.out.println(findPeak(matrix));
    }

    private static int findPeak(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int maxRow = 0;
        for (int i = 0; i < rows; i++) {
            int maxCol = 0;
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] > matrix[i][maxCol]) {
                    maxCol = j;
                }
           
            }
            if (i > 0 && maxCol < cols - 1 && matrix[i][maxCol] < matrix[i - 1][maxCol] && matrix[i][maxCol] < matrix[i + 1][maxCol]) {
                return matrix[i - 1][maxCol];
            }
            if (maxCol > 0 && maxCol < cols - 1 && matrix[i][maxCol] < matrix[i][maxCol - 1] && matrix[i][maxCol] < matrix[i][maxCol + 1]) {
                return matrix[i][maxCol - 1];
            }
            if (maxCol == 0 && i > 0 && matrix[i][maxCol] < matrix[i - 1][maxCol]) {
                return matrix[i - 1][maxCol];
            }
            if (maxCol == cols - 1 && i > 0 && matrix[i][maxCol] < matrix[i - 1][maxCol]) {
                return matrix[i - 1][maxCol];
            }
            maxRow = i;
        }
        return matrix[maxRow][0];
    }
}
