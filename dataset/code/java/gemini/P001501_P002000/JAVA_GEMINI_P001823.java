import java.util.Stack;

public class Solution {
    public boolean verifyPostorder(int[] postorder) {
        Stack<Integer> stack = new Stack<>();
        int high = Integer.MAX_VALUE;

        for (int i = postorder.length - 1; i >= 0; i--) {
            int p = postorder[i];
            if (p > high) return false;
            // Maintain monotonic stack property by popping smaller elements
            while (!stack.isEmpty() && p < stack.peek()) {
                high = stack.pop();
            }
            stack.push(p);
        }
        return true;
    }
}