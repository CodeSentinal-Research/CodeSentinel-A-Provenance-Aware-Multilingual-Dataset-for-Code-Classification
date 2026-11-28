import java.util.*;

public class Solution {
    public int firstNonRepeating(int[] arr) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int x : arr) freq.put(x, freq.getOrDefault(x, 0) + 1);
        for (int x : arr) {
            if (freq.get(x) == 1) return x;
        }
        return 0;
    }
}