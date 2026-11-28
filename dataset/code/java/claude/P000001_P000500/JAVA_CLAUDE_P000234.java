import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int r=sc.nextInt(),c=sc.nextInt();
int[][]A=new int[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)A[i][j]=sc.nextInt();
boolean[]R=new boolean[r],C=new boolean[c];
for(int i=0;i<r;i++)for(int j=0;j<c;j++)if(A[i][j]==1){R[i]=C[j]=true;}
for(int i=0;i<r;i++){StringBuilder sb=new StringBuilder();for(int j=0;j<c;j++){if(j>0)sb.append(' ');sb.append(R[i]||C[j]?1:A[i][j]);}System.out.println(sb);}}}
