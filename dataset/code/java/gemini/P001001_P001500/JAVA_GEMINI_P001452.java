import java.util.HashSet;
import java.util.Set;

public class Solution {
    private int rev(int n) {
        int res = 0;
        while (n > 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }
        return res;
    }

    public int countDistinct(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int x : nums) {
            set.add(x);
            set.add(rev(x));
        }
        return set.size();
    }
}