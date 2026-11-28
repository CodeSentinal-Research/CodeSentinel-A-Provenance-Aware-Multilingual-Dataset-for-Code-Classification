public class Solution {
    public int countFrequency(int[] nums, int target) {
        int cnt = 0;
        for (int x : nums) if (x == target) cnt++;
        return cnt;
    }
}
