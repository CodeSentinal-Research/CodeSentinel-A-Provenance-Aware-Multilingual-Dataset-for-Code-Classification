import java.util.Arrays;

public class Solution {
    public int maxScore(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        long prefix = 0;
        int score = 0;

        for (int i = n - 1; i >= 0; i--) {
            prefix += nums[i];
            if (prefix > 0) score++;
            else break;
        }
        return score;
    }
}