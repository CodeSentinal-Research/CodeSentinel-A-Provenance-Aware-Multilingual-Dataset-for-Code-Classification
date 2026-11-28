import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt(),t=sc.nextInt();int[]arr=new int[n];int lo=1,hi=0;for(int i=0;i<n;i++){arr[i]=sc.nextInt();if(arr[i]>hi)hi=arr[i];}while(lo<hi){int mid=(lo+hi)/2;long s=0;for(int v:arr)s+=(v+mid-1)/mid;if(s<=t)hi=mid;else lo=mid+1;}System.out.println(lo);}}
