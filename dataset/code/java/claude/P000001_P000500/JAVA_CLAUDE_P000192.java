import java.util.*;
public class Solution {
    public int[] moveNegatives(int[] nums) {
        List<Integer> neg = new ArrayList<>(), pos = new ArrayList<>();
        for (int x : nums) (x < 0 ? neg : pos).add(x);
        int[] res = new int[nums.length]; int k = 0;
        for (int x : neg) res[k++] = x;
        for (int x : pos) res[k++] = x;
        return res;
    }
}
