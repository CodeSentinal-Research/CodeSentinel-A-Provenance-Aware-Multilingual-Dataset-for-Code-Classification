import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();
        int cols = sc.nextInt();
        int[][] matrix = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        
        int maxOnes = -1;
        int maxRow = -1;
        for (int i = 0; i < rows; i++) {
            int ones = 0;
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 1) ones++;
            }
            if (ones > maxOnes) {
                maxOnes = ones;
                maxRow = i;
            }
        }
        System.out.println(maxRow);
    }
}
