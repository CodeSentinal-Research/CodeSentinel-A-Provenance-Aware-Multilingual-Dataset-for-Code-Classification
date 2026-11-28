import java.util.*;

public class Main {
    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    int KthSmallest(TreeNode root, int K) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curr = root;
        while (curr != null || !stack.isEmpty()) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            curr = stack.pop();
            if (--K == 0) {
                return curr.val;
           }
            curr = curr.right;
        }
        return -1;
    }
}
