import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double[][] matrix = new double[n][n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = sc.nextDouble();
            }
        }
        
        // Calculate Determinant using Gaussian Elimination or Recursion
        // For N <= 5, recursion is fine.
        
        System.out.println(determinant(matrix, n));
    }
    
    private static double determinant(double[][] mat, int n) {
        if (n == 1) return mat[0][0];
        if (n == 2) return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
        
        double det = 0;
        for (int i = 0; i < n; i++) {
            double[][] subMatrix = new double[n-1][n-1];
            for (int j = 1; j < n; j++) {
                int colIndex = 0;
                for (int k = 0; k < n; k++) {
                    if (k == i) continue;
                    subMatrix[j-1][colIndex++] = matrix[j][k];
                }
            }
            det += (i % 2 == 0 ? 1 : -1) * mat[0][i] * determinant(subMatrix, n - 1);
        }
        return det;
    }
}
