import java.util.*;
public class Solution {
    public long knapsack01(int[] wt,int[] val,int W){
        long[] dp=new long[W+1];
        for(int i=0;i<wt.length;i++) for(int j=W;j>=wt[i];j--) dp[j]=Math.max(dp[j],dp[j-wt[i]]+val[i]);
        return dp[W];
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(),W=sc.nextInt();
        int[] wt=new int[n],val=new int[n];
        for(int i=0;i<n;i++) wt[i]=sc.nextInt(); for(int i=0;i<n;i++) val[i]=sc.nextInt();
        System.out.println(new Solution().knapsack01(wt,val,W));
    }
}
