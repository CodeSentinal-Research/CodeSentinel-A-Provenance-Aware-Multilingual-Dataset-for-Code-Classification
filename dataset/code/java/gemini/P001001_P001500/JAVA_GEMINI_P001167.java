public class Solution {
    public int minCost(int[][] costs) {
        if (costs == null || costs.length == 0) return 0;
        int r = 0, g = 0, b = 0;
        for (int[] c : costs) {
            int nr = c[0] + Math.min(g, b);
            int ng = c[1] + Math.min(r, b);
            int nb = c[2] + Math.min(r, g);
            r = nr;
            g = ng;
            b = nb;
        }
        return Math.min(r, Math.min(g, b));
    }
}