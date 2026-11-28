import java.util.*;
public class Solution{static int[]arr;static int m;
static boolean ok(long mid){int s=1;long c=0;for(int v:arr){if(v>mid)return false;if(c+v>mid){s++;c=v;}else c+=v;}return s<=m;}
public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt();m=sc.nextInt();arr=new int[n];long lo=0,hi=0;for(int i=0;i<n;i++){arr[i]=sc.nextInt();if(arr[i]>lo)lo=arr[i];hi+=arr[i];}long ans=hi;while(lo<=hi){long mid=(lo+hi)/2;if(ok(mid)){ans=mid;hi=mid-1;}else lo=mid+1;}System.out.println(ans);}}
