import java.util.*;
public class Solution{
public static void main(String[] a){
Scanner sc=new Scanner(System.in);int n=sc.nextInt();
int[][]M=new int[n][n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)M[i][j]=sc.nextInt();
int c=0;for(int i=1;i<n;i++)if(M[c][i]==1)c=i;
for(int i=0;i<n;i++)if(i!=c&&(M[c][i]==1||M[i][c]==0)){System.out.println(-1);return;}
System.out.println(c);}}
