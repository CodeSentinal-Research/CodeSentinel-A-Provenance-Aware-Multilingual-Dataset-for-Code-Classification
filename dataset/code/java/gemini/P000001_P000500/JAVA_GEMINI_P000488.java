import java.util.*;
public class Solution {
    static int largestArea(int[] heights) {
        int[] h = Arrays.copyOf(heights, heights.length + 1);
        Stack<Integer> st = new Stack<>();
        st.push(-1);
        int maxArea = 0;
        for (int i = 0; i < h.length; i++) {
            while (st.peek() != -1 && h[st.peek()] >= h[i]) {
                int height = h[st.pop()];
                int w = i - st.peek() - 1;
                maxArea = Math.max(maxArea, height * w);
            }
            st.push(i);
        }
        return maxArea;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int r = scanner.nextInt(), c = scanner.nextInt();
            int[] heights = new int[c];
            int maxArea = 0;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    int val = scanner.nextInt();
                    heights[j] = (val == 1) ? heights[j] + 1 : 0;
                }
                maxArea = Math.max(maxArea, largestArea(heights));
            }
            System.out.println(maxArea);
        }
    }
}