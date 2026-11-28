import java.util.*;

public class Solution {
    public boolean areElementsContiguous(int[] arr) {
        Set<Integer> set = new HashSet<>();
        int minV = Integer.MAX_VALUE, maxV = Integer.MIN_VALUE;
        for (int x : arr) {
            set.add(x);
            minV = Math.min(minV, x);
            maxV = Math.max(maxV, x);
        }
        return (maxV - minV + 1) == set.size();
    }
}