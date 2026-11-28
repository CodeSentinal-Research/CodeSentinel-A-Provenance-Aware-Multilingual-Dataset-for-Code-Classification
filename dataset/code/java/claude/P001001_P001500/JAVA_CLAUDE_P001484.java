import java.util.*;
public class Solution {
    public int[] twoPointer(long[] arr,long target){
        int lo=0,hi=arr.length-1;
        while(lo<hi){long s=arr[lo]+arr[hi];if(s==target)return new int[]{lo,hi};else if(s<target)lo++;else hi--;}
        return new int[]{-1,-1};
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(); long t=sc.nextLong(); long[] arr=new long[n];
        for(int i=0;i<n;i++) arr[i]=sc.nextLong();
        int[] r=new Solution().twoPointer(arr,t); System.out.println(r[0]+" "+r[1]);
    }
}
