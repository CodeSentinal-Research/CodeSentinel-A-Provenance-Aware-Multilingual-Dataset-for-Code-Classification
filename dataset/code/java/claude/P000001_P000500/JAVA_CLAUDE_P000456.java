import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt(),h=sc.nextInt();int[]p=new int[n];int lo=1,hi=0;for(int i=0;i<n;i++){p[i]=sc.nextInt();if(p[i]>hi)hi=p[i];}while(lo<hi){int mid=(lo+hi)/2;long s=0;for(int v:p)s+=(v+mid-1)/mid;if(s<=h)hi=mid;else lo=mid+1;}System.out.println(lo);}}
