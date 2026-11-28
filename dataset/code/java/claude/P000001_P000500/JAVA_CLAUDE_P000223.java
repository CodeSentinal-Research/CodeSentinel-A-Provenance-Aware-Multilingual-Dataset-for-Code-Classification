import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int n=sc.nextInt();
int[][]a=new int[n][2];for(int i=0;i<n;i++){a[i][0]=sc.nextInt();a[i][1]=sc.nextInt();}
Arrays.sort(a,(p,q)->p[1]-q[1]);int cnt=1,e=a[0][1];
for(int i=1;i<n;i++)if(a[i][0]>=e){cnt++;e=a[i][1];}System.out.println(cnt);}}
