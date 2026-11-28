//3101. Count Alternating Subarrays
//weekly contest 391

class Solution {
    public long countAlternatingSubarrays(int[] nums) {
        int left = 0;
        long count = 0;
        
        for(int right = 0; right<nums.length; right++){
            if(right>0 && nums[right]==nums[right-1]){
                left = right;
            }
            count +=right-left+1;
        }
        return count;
    }
}