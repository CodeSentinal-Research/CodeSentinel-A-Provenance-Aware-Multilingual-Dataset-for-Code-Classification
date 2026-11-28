import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int r=sc.nextInt(),c=sc.nextInt();
int[][]A=new int[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)A[i][j]=sc.nextInt();
for(int i=1;i<r;i++)for(int j=0;j<c;j++){int b=A[i-1][j];if(j>0)b=Math.max(b,A[i-1][j-1]);if(j<c-1)b=Math.max(b,A[i-1][j+1]);A[i][j]+=b;}
int mx=Integer.MIN_VALUE;for(int v:A[r-1])mx=Math.max(mx,v);
System.out.println(mx);}}
