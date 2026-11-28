import java.util.*;
public class Solution {
    public int firstNonRepeating(int[] nums) {
        Map<Integer,Integer> cnt = new LinkedHashMap<>();
        for (int x : nums) cnt.merge(x, 1, Integer::sum);
        for (Map.Entry<Integer,Integer> e : cnt.entrySet())
            if (e.getValue() == 1) return e.getKey();
        return -1;
    }
}
