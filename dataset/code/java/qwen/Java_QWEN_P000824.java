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
        
        int low = 0, high = n * m - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int val = matrix[mid / m][mid % m];
            if(val == target) { System.out.println("true"); return; }
            else if(val < target) low = mid + 1;
            else high = mid - 1;
        }
        System.out.println("false");
    }
}
