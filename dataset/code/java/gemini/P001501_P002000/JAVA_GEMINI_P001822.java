import java.util.Stack;

public class Solution {
    public boolean verifyPreorder(int[] preorder) {
        Stack<Integer> stack = new Stack<>();
        int low = Integer.MIN_VALUE;

        for (int p : preorder) {
            if (p < low) return false;
            // Maintain monotonic stack property by popping smaller elements
            while (!stack.isEmpty() && p > stack.peek()) {
                low = stack.pop();
            }
            stack.push(p);
        }
        return true;
    }
}