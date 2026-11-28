import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] mat = new int[n][n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) mat[i][j] = sc.nextInt();
            
        Map<String, Integer> rowMap = new HashMap<>();
        for(int i=0; i<n; i++) {
            String key = Arrays.toString(mat[i]);
            rowMap.put(key, rowMap.getOrDefault(key, 0) + 1);
        }
        
        int count = 0;
        for(int j=0; j<n; j++) {
            int[] col = new int[n];
            for(int i=0; i<n; i++) col[i] = mat[i][j];
            String key = Arrays.toString(col);
            count += rowMap.getOrDefault(key, 0);
        }
        System.out.println(count);
    }
}
