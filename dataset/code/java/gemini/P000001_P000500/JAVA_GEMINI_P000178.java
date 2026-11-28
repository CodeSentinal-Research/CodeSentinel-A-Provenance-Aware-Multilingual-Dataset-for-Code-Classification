import java.util.*;

public class Solution {
    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int x : nums) freq.put(x, freq.getOrDefault(x, 0) + 1);

        List<Integer> list = new ArrayList<>();
        for (int x : nums) list.add(x);

        list.sort((a, b) -> {
            int fa = freq.get(a), fb = freq.get(b);
            if (fa != fb) return fb - fa;
            return a - b;
        });

        for (int i = 0; i < nums.length; i++) nums[i] = list.get(i);
        return nums;
    }
}