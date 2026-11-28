import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            long[] h = new long[n];
            for (int i = 0; i < n; i++) h[i] = scanner.nextLong();
            long[] left = new long[n], right = new long[n];
            Stack<Integer> st = new Stack<>();
            for (int i = 0; i < n; i++) {
                while (!st.isEmpty() && h[st.peek()] >= h[i]) st.pop();
                left[i] = st.isEmpty() ? h[i] * (i + 1) : left[st.peek()] + h[i] * (i - st.peek());
                st.push(i);
            }
            st.clear();
            // Process from right to left
            for (int i = n - 1; i >= 0; i--) {
                while (!st.isEmpty() && h[st.peek()] >= h[i]) st.pop();
                right[i] = st.isEmpty() ? h[i] * (n - i) : right[st.peek()] + h[i] * (st.peek() - i);
                st.push(i);
            }
            long maxSum = 0;
            for (int i = 0; i < n; i++) {
                maxSum = Math.max(maxSum, left[i] + right[i] - h[i]);
            }
            System.out.println(maxSum);
        }
    }
}