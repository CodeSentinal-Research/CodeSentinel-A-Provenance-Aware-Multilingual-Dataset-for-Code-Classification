public class Solution {
    public int maxProfit(int[] prices) {
        int sold = 0, held = Integer.MIN_VALUE, reset = 0;
        for (int p : prices) {
            int preSold = sold;
            sold = held + p;
            held = Math.max(held, reset - p);
            reset = Math.max(reset, preSold);
        }
        return Math.max(sold, reset);
    }
}