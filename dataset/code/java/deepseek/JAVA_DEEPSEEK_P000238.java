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

        boolean isOrthogonal = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double product = 0.0;
                for (int k = 0; k < n; k++) {
                    product += matrix[i][k] * matrix[j][k];
                }
                if (i == j && product != 1.0 || i != j && product != 0.0) {
                    isOrthogonal = false;
                    break;
               }
            }
        }

        System.out.println(isOrthogonal ? "Yes" : "No");
    }
}
