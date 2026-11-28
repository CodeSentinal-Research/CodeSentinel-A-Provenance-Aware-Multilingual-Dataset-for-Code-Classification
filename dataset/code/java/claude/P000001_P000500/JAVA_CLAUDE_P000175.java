import java.util.Arrays;
public class Solution {
    public int[] waveArray(int[] nums) {
        Arrays.sort(nums);
        for (int i=0;i<nums.length-1;i+=2) {
            int t=nums[i]; nums[i]=nums[i+1]; nums[i+1]=t;
        }
        return nums;
    }
}
