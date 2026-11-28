public class Solution {
    public int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (target > startValue) {
            ans++;
            // If current bit is set, multiply base into result
            if (target % 2 == 1) {
                target++;
            } else {
                target /= 2;
            }
        }
        return ans + startValue - target;
    }
}