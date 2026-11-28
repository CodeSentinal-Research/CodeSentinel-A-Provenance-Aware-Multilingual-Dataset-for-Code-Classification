public class Solution {
    public int getMaxLen(int[] nums) {
        int pos = 0, neg = 0, ans = 0;
        for (int x : nums) {
            if (x == 0) {
                pos = 0;
                neg = 0;
            } else if (x > 0) {
                pos++;
                neg = (neg > 0 ? neg + 1 : 0);
            } else {
                int newPos = (neg > 0 ? neg + 1 : 0);
                int newNeg = pos + 1;
                pos = newPos;
                neg = newNeg;
            }
            ans = Math.max(ans, pos);
        }
        return ans;
    }
}