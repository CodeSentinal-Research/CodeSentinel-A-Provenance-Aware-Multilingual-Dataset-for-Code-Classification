import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        scanner.nextLine();
        int[][] matrix = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        spiralOrder(matrix);
    }

    public static void spiralOrder(int[][] matrix) {
        int top = 0;
        int down = matrix.length - 1;
        int left = 0;
        int right = matrix[0].length - 1;

        while (true) {
            // Print top row
            for (int j = left; j <= right; j++) {
                System.out.print(matrix[top][j] + " ");
            }
            top++;
            if (top > down || left > right) break;

            // Print right column
            for (int i = top; i <= down; i++) {
                System.out.print(matrix[i][right] + " ");
            }
            right--;
            if (top > down || left > right)  break;

            // Print bottom row
            for (int j = right; j >= left; j--) {
                System.out.print(matrix[down][j] + " ");
            }
            down--;
            if (top > down || left > right) break;

            // Print left column
            for (int i = down; i >= top; i--) {
                System.out.print(matrix[i][left] + " ");
            }
            left++;
            if (top > down || left > right) break;
        }
    }
}
