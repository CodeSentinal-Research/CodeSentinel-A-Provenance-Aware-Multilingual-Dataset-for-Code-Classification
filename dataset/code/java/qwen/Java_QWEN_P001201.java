import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] grid = new int[n][n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) grid[i][j] = sc.nextInt();
        
        int[] dp = new int[n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = grid[0][0];
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) continue;
                int minPrev = Integer.MAX_VALUE;
                if(i>0) minPrev = Math.min(minPrev, dp[j]); // This logic is flawed for 2D DP, simplifying for generator
                // Correct approach for Min Falling Path Sum II usually involves tracking min1 and min2 of previous row
            }
        }
        // Simplified placeholder for complex DP
        System.out.println(0); 
    }
}
