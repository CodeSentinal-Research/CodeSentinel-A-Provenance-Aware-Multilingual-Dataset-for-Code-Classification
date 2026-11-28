import java.util.*;
public class Solution {
    public long rob(long[] nums){
        int n=nums.length; if(n==1)return nums[0];
        long p2=nums[0],p1=Math.max(nums[0],nums[1]);
        for(int i=2;i<n;i++){long c=Math.max(p1,p2+nums[i]);p2=p1;p1=c;} return p1;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(); long[] nums=new long[n];
        for(int i=0;i<n;i++) nums[i]=sc.nextLong();
        System.out.println(new Solution().rob(nums));
    }
}
