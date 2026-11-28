import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int n=sc.nextInt();
int[][]A=new int[n][n],sm=new int[n][n];
for(int i=0;i<n;i++)for(int j=0;j<n;j++)A[i][j]=sc.nextInt();
sm[n-1][n-1]=A[n-1][n-1];
for(int j=n-2;j>=0;j--)sm[n-1][j]=Math.max(A[n-1][j],sm[n-1][j+1]);
for(int i=n-2;i>=0;i--)sm[i][n-1]=Math.max(A[i][n-1],sm[i+1][n-1]);
for(int i=n-2;i>=0;i--)for(int j=n-2;j>=0;j--)sm[i][j]=Math.max(A[i][j],Math.max(sm[i+1][j],sm[i][j+1]));
int ans=Integer.MIN_VALUE;
for(int i=0;i<n-1;i++)for(int j=0;j<n-1;j++)ans=Math.max(ans,sm[i+1][j+1]-A[i][j]);
System.out.println(ans);}}
