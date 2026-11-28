import java.util.Arrays;

public class Solution {
    public int maxProfit(int k, int[] prices) {
        if (prices == null || prices.length == 0 || k == 0) return 0;
        int n = prices.length;
        if (k >= n / 2) {
            int res = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
            }
            return res;
        }

        int[] buy = new int[k + 1];
        int[] profit = new int[k + 1];
        Arrays.fill(buy, Integer.MAX_VALUE);

        for (int p : prices) {
            for (int i = 1; i <= k; i++) {
                buy[i] = Math.min(buy[i], p - profit[i - 1]);
                profit[i] = Math.max(profit[i], p - buy[i]);
            }
        }
        return profit[k];
    }
}