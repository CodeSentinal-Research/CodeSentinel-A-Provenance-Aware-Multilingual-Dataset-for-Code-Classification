import java.util.*;
public class Solution {
    public int[] findUnion(int[] a, int[] b) {
        TreeSet<Integer> s = new TreeSet<>();
        for (int x : a) s.add(x);
        for (int x : b) s.add(x);
        return s.stream().mapToInt(Integer::intValue).toArray();
    }
}
