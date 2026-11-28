import java.util.Scanner;
public class Solution {
    public int minDistance(String s1,String s2){
        int m=s1.length(),n=s2.length(); int[][] dp=new int[m+1][n+1];
        for(int i=0;i<=m;i++) dp[i][0]=i; for(int j=0;j<=n;j++) dp[0][j]=j;
        for(int i=1;i<=m;i++) for(int j=1;j<=n;j++)
            dp[i][j]=s1.charAt(i-1)==s2.charAt(j-1)?dp[i-1][j-1]:1+Math.min(dp[i-1][j-1],Math.min(dp[i-1][j],dp[i][j-1]));
        return dp[m][n];
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println(new Solution().minDistance(sc.next(),sc.next()));
    }
}
