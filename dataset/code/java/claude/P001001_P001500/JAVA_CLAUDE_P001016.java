import java.util.*;
public class Solution {
    public long maxSlidingWindow(long[] arr,int k){
        long s=0,mx; for(int i=0;i<k;i++) s+=arr[i]; mx=s;
        for(int i=k;i<arr.length;i++){s+=arr[i]-arr[i-k];mx=Math.max(mx,s);} return mx;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(),k=sc.nextInt(); long[] arr=new long[n];
        for(int i=0;i<n;i++) arr[i]=sc.nextLong();
        System.out.println(new Solution().maxSlidingWindow(arr,k));
    }
}
