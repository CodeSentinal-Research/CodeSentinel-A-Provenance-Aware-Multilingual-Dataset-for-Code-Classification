import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] matrix = new int[n][m];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) matrix[i][j] = sc.nextInt();
        int target = sc.nextInt();
        
        int r = 0, c = m - 1;
        while(r < n && c >= 0) {
            if(matrix[r][c] == target) { System.out.println("true"); return; }
            else if(matrix[r][c] > target) c--;
            else r++;
        }
        System.out.println("false");
    }
}
