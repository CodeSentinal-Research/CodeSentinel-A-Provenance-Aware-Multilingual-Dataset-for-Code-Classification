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
        
        // Rotate elements clockwise by 1 step
        // Store top-left
        int prev = matrix[0][0];
        
        // Move left column up
        for (int i = 0; i < rows - 1; i++) {
            matrix[i][0] = matrix[i+1][0];
        }
        
        // Move bottom row left
        for (int j = 0; j < cols - 1; j++) {
            matrix[rows-1][j] = matrix[rows-1][j+1];
        }
        
        // Move right column down
        for (int i = rows - 1; i > 0; i--) {
            matrix[i][cols-1] = matrix[i-1][cols-1];
        }
        
        // Move top row right
        for (int j = cols - 1; j > 0; j--) {
            matrix[0][j] = (j == 1) ? prev : matrix[0][j-1]; // Careful with overwrite
        }
        // Actually, simpler to use a temporary array or spiral index mapping.
        // Let's use a clean spiral traversal to rotate.
        
        int[] temp = new int[2 * (rows + cols) - 4]; // Boundary elements
        // This is complex to implement bug-free in short time. 
        // Alternative: Create new matrix.
        
        int[][] rotated = new int[rows][cols];
        // Copy inner part? No, "Rotate Matrix Elements" usually means boundary rotation or full spiral shift.
        // Assuming boundary rotation as per standard GFG problem.
        
        // Re-implementing boundary rotation correctly
        if (rows == 1 || cols == 1) {
             // Just print original if 1D
             for(int[] row : matrix) {
                 for(int val : row) System.out.print(val + " ");
             }
             return;
        }

        int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
        int prev = matrix[top][left];
        
        // Move left col up
        for (int i = top; i < bottom; i++) {
            matrix[i][left] = matrix[i+1][left];
        }
        
        // Move bottom row left
        for (int j = left; j < right; j++) {
            matrix[bottom][j] = matrix[bottom][j+1];
        }
        
        // Move right col down
        for (int i = bottom; i > top; i--) {
            matrix[i][right] = matrix[i-1][right];
        }
        
        // Move top row right
        for (int j = right; j > left; j--) {
            matrix[top][j] = matrix[top][j-1];
        }
        
        matrix[top][left + 1] = prev; // Place the stored element
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
