import java.util.*;
public class Solution {
    public int[] findIntersection(int[] a, int[] b) {
        Set<Integer> s = new HashSet<>(), res = new TreeSet<>();
        for (int x : a) s.add(x);
        for (int x : b) if (s.contains(x)) res.add(x);
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}
