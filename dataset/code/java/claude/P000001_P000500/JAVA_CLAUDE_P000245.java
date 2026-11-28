import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int n=sc.nextInt();
int[][]A=new int[n][n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)A[i][j]=sc.nextInt();
for(int i=0;i<n;i++){StringBuilder sb=new StringBuilder();for(int j=0;j<n;j++){if(j>0)sb.append(' ');sb.append(j<=i?A[i][j]:0);}System.out.println(sb);}}}
