import java.util.*;
public class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        Map<Integer,Integer> order = new HashMap<>();
        for (int i = 0; i < arr2.length; i++) order.put(arr2[i], i);
        Integer[] res = new Integer[arr1.length];
        for (int i = 0; i < arr1.length; i++) res[i] = arr1[i];
        Arrays.sort(res, (a, b) -> {
            boolean ha = order.containsKey(a), hb = order.containsKey(b);
            if (ha && hb) return order.get(a) - order.get(b);
            if (ha) return -1;
            if (hb) return 1;
            return a - b;
        });
        for (int i = 0; i < arr1.length; i++) arr1[i] = res[i];
        return arr1;
    }
}
