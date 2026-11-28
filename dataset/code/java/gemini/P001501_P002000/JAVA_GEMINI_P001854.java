import java.util.Stack;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public TreeNode buildCartesianTree(int[] inorder) {
        Stack<TreeNode> stack = new Stack<>();

        for (int val : inorder) {
            TreeNode last = null;
            // Maintain monotonic stack property by popping smaller elements
            while (!stack.isEmpty() && stack.peek().val > val) {
                last = stack.pop();
            }
            TreeNode node = new TreeNode(val);
            node.left = last;
            if (!stack.isEmpty()) {
                stack.peek().right = node;
            }
            stack.push(node);
        }

        while (stack.size() > 1) stack.pop();
        return stack.isEmpty() ? null : stack.peek();
    }
}