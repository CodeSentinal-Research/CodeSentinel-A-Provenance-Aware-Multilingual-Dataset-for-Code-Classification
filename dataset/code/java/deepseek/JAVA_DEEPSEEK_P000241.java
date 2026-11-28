import java.util.Scanner;

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
        boolean hasSaddlePoint = false;
        for (int i = 0; i < n; i++) {
            int minRow = Integer.MAX_VALUE;
            int minRowIndex = -1;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < minRow) {
                    minRow = matrix[i][j];
                    minRowIndex = j;
                }
            }
            boolean isSaddlePoint = true;
            for (int k = 0; k < n; k++) {
                if (matrix[k][minRowIndex] > minRow) {
                    isSaddlePoint = false;
                    break;
                }
           }
            if (isSaddlePoint) {
                System.out.println(minRow);
                hasSaddlePoint = true;
                break;
            }
        }
        if (!hasSaddlePoint) {
            System.out.println("No Saddle Point");
        }
    }
}
