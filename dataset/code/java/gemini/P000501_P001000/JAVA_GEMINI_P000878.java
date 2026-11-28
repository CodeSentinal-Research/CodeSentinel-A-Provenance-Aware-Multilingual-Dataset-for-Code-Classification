import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int subarrayBitwiseORs(int[] arr) {
        Set<Integer> res = new HashSet<>();
        Set<Integer> cur = new HashSet<>();
        for (int x : arr) {
            Set<Integer> next = new HashSet<>();
            next.add(x);
            for (int y : cur) {
                next.add(x | y);
            }
            cur = next;
            res.addAll(cur);
        }
        return res.size();
    }
}