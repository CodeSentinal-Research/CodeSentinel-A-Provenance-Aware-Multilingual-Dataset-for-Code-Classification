public class Solution {
    public int secondLargest(int[] nums) {
        int first = Integer.MIN_VALUE, second = Integer.MIN_VALUE;
        for (int x : nums) {
            if (x > first) { second = first; first = x; }
            else if (x > second && x != first) second = x;
        }
        return second == Integer.MIN_VALUE ? -1 : second;
    }
}
