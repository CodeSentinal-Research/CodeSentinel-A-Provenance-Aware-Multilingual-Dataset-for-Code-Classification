public class Solution {
    public int findMaxConsecutiveZeros(int[] nums) {
        int best = 0, cur = 0;
        for (int x : nums) {
            cur = (x == 0) ? cur + 1 : 0;
            if (cur > best) best = cur;
        }
        return best;
    }
}
