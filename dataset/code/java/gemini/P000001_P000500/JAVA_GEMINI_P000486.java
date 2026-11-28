import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            long[] heights = new long[n + 1];
            for (int i = 0; i < n; i++) heights[i] = scanner.nextLong();
            heights[n] = 0;
            Stack<Integer> st = new Stack<>();
            st.push(-1);
            long maxArea = 0;
            for (int i = 0; i <= n; i++) {
                while (st.peek() != -1 && heights[st.peek()] >= heights[i]) {
                    long h = heights[st.pop()];
                    long w = i - st.peek() - 1;
                    maxArea = Math.max(maxArea, h * w);
                }
                st.push(i);
            }
            System.out.println(maxArea);
        }
    }
}