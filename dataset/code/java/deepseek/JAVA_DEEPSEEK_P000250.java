import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        double[][] matrix = new double[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = scanner.nextDouble();
            }
        }
        System.out.println(calculateDeterminant(matrix));
    }

    private static double calculateDeterminant(double[][] matrix) {
        if (matrix.length == 1) {
            return matrix[0][0];
        }
        double determinant = 0;
        for (int i = 0; i < matrix.length; i++) {
            determinant += matrix[0][i] * cofactor(matrix, 0, i);
        }
        return determinant;
    }

    private static double cofactor(double[][] matrix, int row, int column) {
        double[][] subMatrix = new double[matrix.length - 1][matrix.length - 1];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                if (i < row && j < column) {
                    subMatrix[i][j] = matrix[i][j];
                } else if (i < row && j > column) {
                    subMatrix[i][j - 1] = matrix[i][j];
               
               } else if (i > row && j < column) {
                    subMatrix[i - 1][j] = matrix[i][j];
               } else if (i > row && j > column) {
                    subMatrix[i - 1][j - 1] = matrix[i][j];
               }
            }
        }
        return Math.pow(-1, row + column) * calculateDeterminant(subMatrix);
    }
}
