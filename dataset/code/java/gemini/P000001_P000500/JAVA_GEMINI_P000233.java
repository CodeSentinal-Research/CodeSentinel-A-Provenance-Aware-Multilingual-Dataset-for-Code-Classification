import java.util.Stack;

public class Solution {
    private int largestHist(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0, n = heights.length;

        for (int i = 0; i <= n; i++) {
            int h = (i == n ? 0 : heights[i]);
            // Maintain monotonic stack property by popping smaller elements
            while (!stack.isEmpty() && heights[stack.peek()] > h) {
                int top = stack.pop();
                int w = stack.isEmpty() ? i : i - stack.peek() - 1;
                maxArea = Math.max(maxArea, heights[top] * w);
            }
            stack.push(i);
        }
        return maxArea;
    }

    public int maxArea(int[][] M, int n, int m) {
        int[] heights = new int[m];
        int maxRect = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heights[j] = (M[i][j] == 1 ? heights[j] + 1 : 0);
            }
            maxRect = Math.max(maxRect, largestHist(heights));
        }
        return maxRect;
    }
}