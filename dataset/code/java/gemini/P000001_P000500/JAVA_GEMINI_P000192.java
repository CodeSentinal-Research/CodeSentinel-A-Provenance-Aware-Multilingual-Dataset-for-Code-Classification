import java.util.*;

public class Solution {
    public void segregateElements(int[] arr, int n) {
        List<Integer> pos = new ArrayList<>();
        List<Integer> neg = new ArrayList<>();
        for (int x : arr) {
            if (x >= 0) pos.add(x);
            else neg.add(x);
        }
        int idx = 0;
        for (int x : pos) arr[idx++] = x;
        for (int x : neg) arr[idx++] = x;
    }
}