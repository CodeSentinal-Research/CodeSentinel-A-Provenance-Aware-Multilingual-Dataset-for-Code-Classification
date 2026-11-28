import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int n=sc.nextInt();
int[][]j=new int[n][3];int md=0;
for(int i=0;i<n;i++){j[i][0]=sc.nextInt();j[i][1]=sc.nextInt();j[i][2]=sc.nextInt();md=Math.max(md,j[i][1]);}
Arrays.sort(j,(a,b)->b[2]-a[2]);int[]slot=new int[md+1];Arrays.fill(slot,-1);
int cnt=0,prof=0;
for(int[]job:j)for(int t=job[1];t>0;t--)if(slot[t]==-1){slot[t]=job[0];cnt++;prof+=job[2];break;}
System.out.println(cnt+" "+prof);}}
