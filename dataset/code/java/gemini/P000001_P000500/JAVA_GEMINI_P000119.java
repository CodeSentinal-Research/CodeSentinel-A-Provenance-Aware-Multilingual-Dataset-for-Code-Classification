import java.util.*;

public class Solution {
    public int[] separateEvenOdd(int[] nums) {
        int[] res = new int[nums.length];
        int l = 0, r = nums.length - 1;
        for (int x : nums) {
            if (x % 2 == 0) res[l++] = x;
        }
        for (int x : nums) {
            if (x % 2 != 0) res[l++] = x;
        }
        return res;
    }
}