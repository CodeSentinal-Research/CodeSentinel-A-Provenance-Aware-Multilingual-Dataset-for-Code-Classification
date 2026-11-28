import java.util.*;

public class Solution {
    public List<Integer> countDistinct(int[] arr, int k) {
        List<Integer> res = new ArrayList<>();
        Map<Integer, Integer> freq = new HashMap<>();
        int distinct = 0;

        for (int i = 0; i < k; i++) {
            freq.put(arr[i], freq.getOrDefault(arr[i], 0) + 1);
            if (freq.get(arr[i]) == 1) distinct++;
        }
        res.add(distinct);

        for (int i = k; i < arr.length; i++) {
            int out = arr[i - k];
            freq.put(out, freq.get(out) - 1);
            if (freq.get(out) == 0) distinct--;

            int inVal = arr[i];
            freq.put(inVal, freq.getOrDefault(inVal, 0) + 1);
            if (freq.get(inVal) == 1) distinct++;

            res.add(distinct);
        }
        return res;
    }
}