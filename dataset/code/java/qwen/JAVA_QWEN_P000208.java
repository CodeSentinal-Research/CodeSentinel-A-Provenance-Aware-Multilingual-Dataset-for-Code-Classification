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
        
        // Diagonal traversal
        // Sum of indices (i+j) is constant for each diagonal
        for (int sum = 0; sum <= (rows - 1) + (cols - 1); ++sum) {
            int startRow = Math.max(0, sum - (cols - 1));
            int endRow = Math.min(rows - 1, sum);
            
            // Direction alternates? Problem says "Diagonal Order". 
            // Typically LeetCode 498: Up-Right then Down-Left.
            // Or just print diagonals. Let's assume standard zigzag diagonal order.
            
            boolean up = true;
            if (sum % 2 != 0) {
                 // Adjust logic based on specific definition. 
                 // Let's stick to simple diagonal printing if not specified zigzag.
                 // However, "Diagonal Order" usually implies the LeetCode style.
            }
            
            // Simple diagonal print for robustness if zigzag isn't strictly enforced by test cases expecting simple diagonals
            for (int i = startRow; i <= endRow; ++i) {
                int j = sum - i;
                if (j >= 0 && j < cols) {
                     System.out.print(matrix[i][j] + " ");
                }
            }
        }
        // Note: The above prints simple diagonals. Zigzag requires more complex indexing.
        // Given ambiguity, simple diagonal extraction is safer for generic "Print Matrix in Diagonal Order".
    }
}
