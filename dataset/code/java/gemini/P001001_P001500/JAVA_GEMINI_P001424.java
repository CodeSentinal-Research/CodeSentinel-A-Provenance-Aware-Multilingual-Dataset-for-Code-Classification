import java.util.*;

public class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int x : arr) count.put(x, count.getOrDefault(x, 0) + 1);

        Set<Integer> set = new HashSet<>(count.values());
        return set.size() == count.size();
    }
}