import java.util.*;
public class Solution {
    public long[] slidingWindowSum(long[] arr,int k){
        int m=arr.length-k+1; long[] res=new long[m]; long s=0;
        for(int i=0;i<k;i++) s+=arr[i]; res[0]=s;
        for(int i=k;i<arr.length;i++){s+=arr[i]-arr[i-k];res[i-k+1]=s;} return res;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(),k=sc.nextInt(); long[] arr=new long[n];
        for(int i=0;i<n;i++) arr[i]=sc.nextLong();
        for(long x:new Solution().slidingWindowSum(arr,k)) System.out.println(x);
    }
}
