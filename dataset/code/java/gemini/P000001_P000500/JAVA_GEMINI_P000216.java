import java.util.*;

public class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, Integer> first = new HashMap<>();
        Map<Integer, Integer> last = new HashMap<>();
        Map<Integer, Integer> count = new HashMap<>();

        int degree = 0;
        for (int i = 0; i < nums.length; i++) {
            int x = nums[i];
            if (!first.containsKey(x)) first.put(x, i);
            last.put(x, i);
            int cnt = count.getOrDefault(x, 0) + 1;
            count.put(x, cnt);
            degree = Math.max(degree, cnt);
        }

        int minLen = nums.length;
        for (int x : count.keySet()) {
            if (count.get(x) == degree) {
                minLen = Math.min(minLen, last.get(x) - first.get(x) + 1);
            }
        }
        return minLen;
    }
}