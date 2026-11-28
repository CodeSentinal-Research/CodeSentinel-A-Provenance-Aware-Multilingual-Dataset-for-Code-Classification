import java.util.*;

public class Solution {
    public List<Integer> majorityElement(int[] nums) {
        Integer c1 = null, c2 = null;
        int cnt1 = 0, cnt2 = 0;

        for (int x : nums) {
            if (c1 != null && x == c1) cnt1++;
            else if (c2 != null && x == c2) cnt2++;
            else if (cnt1 == 0) { c1 = x; cnt1 = 1; }
            else if (cnt2 == 0) { c2 = x; cnt2 = 1; }
            else { cnt1--; cnt2--; }
        }

        cnt1 = 0; cnt2 = 0;
        for (int x : nums) {
            if (c1 != null && x == c1) cnt1++;
            if (c2 != null && x == c2) cnt2++;
        }

        List<Integer> res = new ArrayList<>();
        int n = nums.length;
        if (cnt1 > n / 3) res.add(c1);
        if (c2 != null && !c2.equals(c1) && cnt2 > n / 3) res.add(c2);
        return res;
    }
}