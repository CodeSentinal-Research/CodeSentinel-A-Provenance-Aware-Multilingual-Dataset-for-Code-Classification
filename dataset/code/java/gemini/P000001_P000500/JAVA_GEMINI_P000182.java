import java.util.*;

public class Solution {
    public int mostFrequent(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        int maxCnt = 0, best = nums[0];
        for (int x : nums) {
            int cnt = freq.getOrDefault(x, 0) + 1;
            freq.put(x, cnt);
            if (cnt > maxCnt) {
                maxCnt = cnt;
                best = x;
            }
        }
        return best;
    }
}