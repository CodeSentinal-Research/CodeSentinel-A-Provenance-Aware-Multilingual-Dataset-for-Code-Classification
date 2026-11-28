import java.util.*;
public class Solution {
    public int coinChange(int[] coins,int amount){
        int[] dp=new int[amount+1]; Arrays.fill(dp,Integer.MAX_VALUE); dp[0]=0;
        for(int i=1;i<=amount;i++) for(int c:coins) if(c<=i&&dp[i-c]!=Integer.MAX_VALUE) dp[i]=Math.min(dp[i],dp[i-c]+1);
        return dp[amount]==Integer.MAX_VALUE?-1:dp[amount];
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(),amt=sc.nextInt(); int[] coins=new int[n];
        for(int i=0;i<n;i++) coins[i]=sc.nextInt();
        System.out.println(new Solution().coinChange(coins,amt));
    }
}
