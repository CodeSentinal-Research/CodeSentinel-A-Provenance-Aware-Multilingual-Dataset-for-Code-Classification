public class Solution {
    public int secondSmallest(int[] nums) {
        int first = Integer.MAX_VALUE, second = Integer.MAX_VALUE;
        for (int x : nums) {
            if (x < first) { second = first; first = x; }
            else if (x < second && x != first) second = x;
        }
        return second == Integer.MAX_VALUE ? -1 : second;
    }
}
