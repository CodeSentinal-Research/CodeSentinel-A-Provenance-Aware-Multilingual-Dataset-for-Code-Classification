import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int n=sc.nextInt();
int[][]A=new int[n][n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)A[i][j]=sc.nextInt();
for(int i=0;i<n;i++){int mn=Integer.MAX_VALUE,jm=0;for(int j=0;j<n;j++)if(A[i][j]<mn){mn=A[i][j];jm=j;}boolean ok=true;for(int k=0;k<n;k++)if(A[k][jm]<mn)ok=false;if(ok){System.out.println(i+" "+jm+" "+mn);return;}}
System.out.println("No Saddle Point");}}
