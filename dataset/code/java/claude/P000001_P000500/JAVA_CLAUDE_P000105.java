public class Solution {
    public int[] countEvenOdd(int[] nums) {
        int even = 0;
        for (int x : nums) if (x % 2 == 0) even++;
        return new int[]{even, nums.length - even};
    }
}
