import java.util.*;
public class Solution {
    public List<Integer> findLeaders(int[] nums) {
        List<Integer> leaders = new ArrayList<>();
        if (nums.length == 0) return leaders;
        int maxRight = nums[nums.length - 1];
        leaders.add(maxRight);
        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] >= maxRight) {
                maxRight = nums[i];
                leaders.add(maxRight);
            }
        }
        Collections.reverse(leaders);
        return leaders;
    }
}
