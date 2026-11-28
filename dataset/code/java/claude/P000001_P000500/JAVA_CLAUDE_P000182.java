import java.util.*;
public class Solution {
    public int mostFrequent(int[] nums) {
        Map<Integer,Integer> cnt = new HashMap<>();
        for (int x : nums) cnt.merge(x, 1, Integer::sum);
        return Collections.max(cnt.entrySet(), Map.Entry.comparingByValue()).getKey();
    }
}
