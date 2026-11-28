import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] piles = new int[n];
        long sum = 0;
        for(int i=0; i<n; i++) {
            piles[i] = sc.nextInt();
            sum += piles[i];
        }
        
        int[][] memo = new int[n][n+1];
        for(int[] row : memo) Arrays.fill(row, -1);
        
        System.out.println(stoneGameII(piles, 0, 1, memo));
    }
    
    static int stoneGameII(int[] piles, int i, int m, int[][] memo) {
        if(i >= piles.length) return 0;
        if(memo[i][m] != -1) return memo[i][m];
        
        int total = 0;
        int maxStones = 0;
        for(int x=1; x<=2*m && i+x-1 < piles.length; x++) {
            total += piles[i+x-1];
            maxStones = Math.max(maxStones, total - stoneGameII(piles, i+x, Math.max(m, x), memo));
        }
        memo[i][m] = maxStones;
        return maxStones;
    }
}
