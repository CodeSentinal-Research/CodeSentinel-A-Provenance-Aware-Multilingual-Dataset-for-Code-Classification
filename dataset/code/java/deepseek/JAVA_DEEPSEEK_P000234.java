import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        boolean[][] matrix = new boolean[rows][cols];
        boolean[] rowFlags = new boolean[rows];
        boolean[] colFlags = new boolean[cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = scanner.nextInt() == 1;
                if (matrix[i][j]) {
                    rowFlags[i] = true;
                    colFlags[j] = true;
                }
            }
       }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (rowFlags[i] || colFlags[j]) {
                    System.out.print(1 + " ");
                } else {
                    System.out.print(0 + " ");
                }
            }
            System.out.println();
        }
    }
}
