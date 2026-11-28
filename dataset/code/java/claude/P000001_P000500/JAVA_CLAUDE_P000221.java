import java.util.*;
public class Solution{
public static void main(String[] a){
Scanner sc=new Scanner(System.in);int n=sc.nextInt();
int[][]p=new int[n][2];for(int i=0;i<n;i++){p[i][0]=sc.nextInt();p[i][1]=sc.nextInt();}
Arrays.sort(p,(x,y)->x[1]-y[1]);int cnt=1,e=p[0][1];
for(int i=1;i<n;i++)if(p[i][0]>e){cnt++;e=p[i][1];}
System.out.println(cnt);}}
