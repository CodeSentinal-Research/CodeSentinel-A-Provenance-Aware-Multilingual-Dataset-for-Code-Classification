import java.util.*;
public class Solution{public static void main(String[]a){String s=new Scanner(System.in).next();int n=s.length(),best=0;int[]dp=new int[n];for(int i=1;i<n;i++){if(s.charAt(i)==")"){if(s.charAt(i-1)=="(")dp[i]=(i>=2?dp[i-2]:0)+2;else if(dp[i-1]>0){int j=i-dp[i-1]-1;if(j>=0&&s.charAt(j)=="(")dp[i]=dp[i-1]+2+(j>0?dp[j-1]:0);}best=Math.max(best,dp[i]);}}System.out.println(best);}}
