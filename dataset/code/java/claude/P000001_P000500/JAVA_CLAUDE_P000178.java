import java.util.*;
public class Solution {
    public int[] frequencySort(int[] nums) {
        Map<Integer,Integer> cnt = new HashMap<>();
        for (int x : nums) cnt.merge(x, 1, Integer::sum);
        Integer[] boxed = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) boxed[i] = nums[i];
        Arrays.sort(boxed, (a, b) -> cnt.get(a).equals(cnt.get(b)) ? a - b : cnt.get(b) - cnt.get(a));
        for (int i = 0; i < nums.length; i++) nums[i] = boxed[i];
        return nums;
    }
}
