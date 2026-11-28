import java.util.*;
public class Main {
    static int[] piles;
    static Integer[][] memo;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        piles = new int[n];
        int sum = 0;
        for(int i=0; i<n; i++) {
            piles[i] = sc.nextInt();
            sum += piles[i];
        }
        memo = new Integer[n][n+1];
        int alice = solve(0, 1, sum);
        System.out.println(alice);
    }
    static int solve(int i, int m, int remaining) {
        if(i >= piles.length) return 0;
        if(memo[i][m] != null) return memo[i][m];
        
        int maxTake = Math.min(piles.length - i, 2 * m);
        int currentSum = 0;
        int best = 0;
        
        for(int x=1; x<=maxTake; x++) {
            currentSum += piles[i + x - 1];
            int nextM = Math.max(m, x);
            int opponent = solve(i + x, nextM, remaining - currentSum);
            best = Math.max(best, currentSum + (remaining - currentSum - opponent));
        }
        memo[i][m] = best;
        return best;
    }
}
