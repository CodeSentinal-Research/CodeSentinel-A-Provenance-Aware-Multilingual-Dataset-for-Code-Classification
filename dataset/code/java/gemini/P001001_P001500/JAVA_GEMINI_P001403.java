import java.util.*;

public class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> res = new ArrayList<>();
        int m = l.length;

        for (int i = 0; i < m; i++) {
            int left = l[i], right = r[i];
            int[] sub = Arrays.copyOfRange(nums, left, right + 1);
            Arrays.sort(sub);

            boolean isArith = true;
            int diff = sub[1] - sub[0];
            for (int j = 2; j < sub.length; j++) {
                if (sub[j] - sub[j - 1] != diff) {
                    isArith = false;
                    break;
                }
            }
            res.add(isArith);
        }
        return res;
    }
}