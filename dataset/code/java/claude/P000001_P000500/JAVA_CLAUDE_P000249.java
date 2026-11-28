import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int r1=sc.nextInt(),c1=sc.nextInt(),c2=sc.nextInt();
long[][]A=new long[r1][c1],B=new long[c1][c2],C=new long[r1][c2];
for(int i=0;i<r1;i++)for(int j=0;j<c1;j++)A[i][j]=sc.nextLong();
for(int i=0;i<c1;i++)for(int j=0;j<c2;j++)B[i][j]=sc.nextLong();
for(int i=0;i<r1;i++)for(int j=0;j<c2;j++)for(int k=0;k<c1;k++)C[i][j]+=A[i][k]*B[k][j];
for(int i=0;i<r1;i++){StringBuilder sb=new StringBuilder();for(int j=0;j<c2;j++){if(j>0)sb.append(' ');sb.append(C[i][j]);}System.out.println(sb);}}}
