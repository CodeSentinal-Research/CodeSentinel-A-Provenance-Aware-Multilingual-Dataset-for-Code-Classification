import java.util.*;
public class Solution {
    public int[] separateEvenOdd(int[] nums) {
        List<Integer> evens = new ArrayList<>(), odds = new ArrayList<>();
        for (int x : nums) (x % 2 == 0 ? evens : odds).add(x);
        int[] res = new int[nums.length];
        int k = 0;
        for (int e : evens) res[k++] = e;
        for (int o : odds)  res[k++] = o;
        return res;
    }
}
