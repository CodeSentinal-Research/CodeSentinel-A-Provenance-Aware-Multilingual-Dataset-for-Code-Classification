import java.util.*;
public class Main {
    static int R, C, K;
    static int[][][] memo;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        R = sc.nextInt();
        C = sc.nextInt();
        K = sc.nextInt();
        int sr = sc.nextInt();
        int scCol = sc.nextInt();
        
        memo = new int[K+1][R][C];
        for(int[][] layer : memo)
            for(int[] row : layer) Arrays.fill(row, -1);
            
        System.out.println(findPaths(R, C, K, sr, scCol));
    }
    
    static int findPaths(int m, int n, int maxMove, int r, int c) {
        if(r < 0 || r >= m || c < 0 || c >= n) return 1;
        if(maxMove == 0) return 0;
        if(memo[maxMove][r][c] != -1) return memo[maxMove][r][c];
        
        int MOD = 1000000007;
        long res = 0;
        res += findPaths(m, n, maxMove-1, r-1, c);
        res += findPaths(m, n, maxMove-1, r+1, c);
        res += findPaths(m, n, maxMove-1, r, c-1);
        res += findPaths(m, n, maxMove-1, r, c+1);
        
        memo[maxMove][r][c] = (int)(res % MOD);
        return memo[maxMove][r][c];
    }
}
