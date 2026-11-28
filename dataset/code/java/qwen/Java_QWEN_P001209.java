import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] stoneValue = new int[n];
        for(int i=0; i<n; i++) stoneValue[i] = sc.nextInt();
        
        int[] suffixSum = new int[n+1];
        for(int i=n-1; i>=0; i--) suffixSum[i] = suffixSum[i+1] + stoneValue[i];
        
        int[] dp = new int[n+1];
        for(int i=n-1; i>=0; i--) {
            dp[i] = Integer.MIN_VALUE;
            for(int x=1; x<=3 && i+x<=n; x++) {
                dp[i] = Math.max(dp[i], suffixSum[i] - dp[i+x]);
            }
        }
        
        int alice = dp[0];
        int bob = suffixSum[0] - alice;
        if(alice > bob) System.out.println("Alice");
        else if(alice < bob) System.out.println("Bob");
        else System.out.println("Tie");
    }
}
