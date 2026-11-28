import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();
        int cols = sc.nextInt();
        int[][] grid = new int[rows][cols];
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = sc.nextInt();
            }
        }
        
        int maxSum = Integer.MIN_VALUE;
        
        // Hourglass shape:
        // a b c
        //   d
        // e f g
        
        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                int sum = 0;
                // Top row
                sum += grid[i][j] + grid[i][j+1] + grid[i][j+2];
                // Middle
                sum += grid[i+1][j+1];
                // Bottom row
                sum += grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                
                if (sum > maxSum) {
                    maxSum = sum;
                }
            }
        }
        
        System.out.println(maxSum);
    }
}
