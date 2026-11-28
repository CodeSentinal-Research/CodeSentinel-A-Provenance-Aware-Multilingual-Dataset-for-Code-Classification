import java.util.*;
public class Solution{
static long kadane(long[]a){long b=Long.MIN_VALUE,c=0,mn=0;for(long x:a){c+=x;b=Math.max(b,c-mn);mn=Math.min(mn,c);}return b;}
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int r=sc.nextInt(),c=sc.nextInt();
long[][]A=new long[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)A[i][j]=sc.nextLong();
long best=Long.MIN_VALUE;
for(int l=0;l<c;l++){long[]row=new long[r];for(int ri=l;ri<c;ri++){for(int i=0;i<r;i++)row[i]+=A[i][ri];best=Math.max(best,kadane(row));}}System.out.println(best);}}
