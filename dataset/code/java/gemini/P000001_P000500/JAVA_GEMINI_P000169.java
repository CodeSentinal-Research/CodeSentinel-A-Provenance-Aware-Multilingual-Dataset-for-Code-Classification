import java.util.*;

public class Solution {
    public int firstRepeated(int[] arr) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int x : arr) freq.put(x, freq.getOrDefault(x, 0) + 1);
        for (int i = 0; i < arr.length; i++) {
            if (freq.get(arr[i]) > 1) return i + 1;
        }
        return -1;
    }
}