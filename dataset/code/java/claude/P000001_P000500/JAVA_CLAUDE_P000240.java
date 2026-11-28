import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int r=sc.nextInt(),c=sc.nextInt();
int[][]A=new int[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)A[i][j]=sc.nextInt();
long s=0;for(int j=0;j<c;j++)s+=A[0][j]+A[r-1][j];for(int i=1;i<r-1;i++)s+=A[i][0]+A[i][c-1];
System.out.println(s);}}
