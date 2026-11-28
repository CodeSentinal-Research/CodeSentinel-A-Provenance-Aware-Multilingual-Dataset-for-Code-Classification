public class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int a = 0, b = 0;
        for (int x : cost) {
            int next = Math.min(a, b) + x;
            a = b;
            b = next;
        }
        return Math.min(a, b);
    }
}