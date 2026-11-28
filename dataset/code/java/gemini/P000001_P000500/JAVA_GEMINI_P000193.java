import java.util.*;

public class Solution {
    public int doUnion(int[] arr1, int n, int[] arr2, int m) {
        Set<Integer> set = new HashSet<>();
        for (int x : arr1) set.add(x);
        for (int x : arr2) set.add(x);
        return set.size();
    }
}