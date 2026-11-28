import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] matrix = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        
        // Main diagonal
        for (int i = 0; i < n; i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(matrix[i][i]);
        }
        System.out.println();
        
        // Anti-diagonal
        for (int i = 0; i < n; i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(matrix[i][n - 1 - i]);
        }
        System.out.println();
    }
}
