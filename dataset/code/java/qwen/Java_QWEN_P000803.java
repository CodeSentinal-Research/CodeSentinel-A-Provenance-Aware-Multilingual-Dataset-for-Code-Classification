import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] grid = new int[n][m];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) grid[i][j] = sc.nextInt();
        int target = sc.nextInt();
        
        int count = 0;
        for(int r1=0; r1<n; r1++) {
            int[] colSum = new int[m];
            for(int r2=r1; r2<n; r2++) {
                for(int c=0; c<m; c++) colSum[c] += grid[r2][c];
                
                Map<Integer, Integer> map = new HashMap<>();
                map.put(0, 1);
                int sum = 0;
                for(int c=0; c<m; c++) {
                    sum += colSum[c];
                    count += map.getOrDefault(sum - target, 0);
                    map.put(sum, map.getOrDefault(sum, 0) + 1);
                }
            }
        }
        System.out.println(count);
    }
}
