import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int r=sc.nextInt(),c=sc.nextInt();
int[][]A=new int[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)A[i][j]=sc.nextInt();
List<Integer>res=new ArrayList<>();
for(int j=0;j<c;j++)res.add(A[0][j]);
for(int i=1;i<r-1;i++){res.add(A[i][0]);res.add(A[i][c-1]);}
if(r>1)for(int j=0;j<c;j++)res.add(A[r-1][j]);
StringJoiner sj=new StringJoiner(" ");for(int v:res)sj.add(String.valueOf(v));System.out.println(sj);}}
