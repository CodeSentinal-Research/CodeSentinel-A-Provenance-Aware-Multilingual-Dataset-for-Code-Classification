import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();
        int cols = sc.nextInt();
        int[][] matrix = new int[rows][cols];
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++) matrix[i][j] = sc.nextInt();
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                boolean isPeak = true;
                if(i > 0 && matrix[i][j] <= matrix[i-1][j]) isPeak = false;
                if(i < rows-1 && matrix[i][j] <= matrix[i+1][j]) isPeak = false;
                if(j > 0 && matrix[i][j] <= matrix[i][j-1]) isPeak = false;
                if(j < cols-1 && matrix[i][j] <= matrix[i][j+1]) isPeak = false;
                if(isPeak) { System.out.println(matrix[i][j]); return; }
            }
        }
    }
}
