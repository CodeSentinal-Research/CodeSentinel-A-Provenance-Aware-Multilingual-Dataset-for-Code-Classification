import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int r=sc.nextInt(),c=sc.nextInt();
int[][]A=new int[r][c],B=new int[r][c];
for(int i=0;i<r;i++)for(int j=0;j<c;j++)A[i][j]=sc.nextInt();
for(int i=0;i<r;i++)for(int j=0;j<c;j++)B[i][j]=sc.nextInt();
for(int i=0;i<r;i++){StringBuilder sb=new StringBuilder();for(int j=0;j<c;j++){if(j>0)sb.append(' ');sb.append(A[i][j]+B[i][j]);}System.out.println(sb);}}}
