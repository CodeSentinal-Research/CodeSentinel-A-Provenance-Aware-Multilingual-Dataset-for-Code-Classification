import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        scanner.nextLine();
        char[][] matrix = new char[rows][cols];
        for (int i = 0; i < rows; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = line.charAt(j);
            }
        }
        for (int i = 0; i < cols; i++) {
            System.out.print(matrix[0][i]);
        }
        for (int i = 1; i < rows; i++) {
            System.out.print(matrix[i][cols - 1]);
        }
        for (int i = cols - 2; i >= 0; i--) {
            System.out.print(matrix[rows - 1][i]);
        }
        for (int i = rows - 2; i > 0; i--) {
            System.out.print(matrix[i][0]);
        }
    }
}
