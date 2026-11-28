import java.util.*;
public class Solution {
    public List<Integer> majorityElementNBy3(int[] nums) {
        int c1 = 0, c2 = 1, cnt1 = 0, cnt2 = 0;
        for (int x : nums) {
            if (x == c1) cnt1++;
            else if (x == c2) cnt2++;
            else if (cnt1 == 0) { c1 = x; cnt1 = 1; }
            else if (cnt2 == 0) { c2 = x; cnt2 = 1; }
            else { cnt1--; cnt2--; }
        }
        List<Integer> res = new ArrayList<>();
        int threshold = nums.length / 3;
        cnt1 = cnt2 = 0;
        for (int x : nums) { if (x == c1) cnt1++; else if (x == c2) cnt2++; }
        if (cnt1 > threshold) res.add(c1);
        if (cnt2 > threshold) res.add(c2);
        return res;
    }
}
