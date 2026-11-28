public class Solution {
    public int findOddOccurrence(int[] nums) {
        int res = 0;
        for (int x : nums) res ^= x;
        return res;
    }
}
