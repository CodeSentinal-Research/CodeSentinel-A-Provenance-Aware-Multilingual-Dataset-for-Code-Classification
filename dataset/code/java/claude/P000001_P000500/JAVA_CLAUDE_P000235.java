import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int r=sc.nextInt(),c=sc.nextInt();
int[][]A=new int[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)A[i][j]=sc.nextInt();
StringJoiner sj=new StringJoiner(" ");
for(int i=0;i<r;i++){if(i%2==0)for(int j=0;j<c;j++)sj.add(String.valueOf(A[i][j]));else for(int j=c-1;j>=0;j--)sj.add(String.valueOf(A[i][j]));}
System.out.println(sj);}}
