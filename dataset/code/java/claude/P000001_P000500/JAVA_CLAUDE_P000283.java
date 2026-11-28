import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);String s1=sc.next(),s2=sc.next();int m=s1.length(),n=s2.length();int[][]dp=new int[m+1][n+1];for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)dp[i][j]=s1.charAt(i-1)==s2.charAt(j-1)?dp[i-1][j-1]+1:Math.max(dp[i-1][j],dp[i][j-1]);System.out.println(dp[m][n]);}}
