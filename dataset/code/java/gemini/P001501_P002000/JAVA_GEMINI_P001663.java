import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public boolean isCompleteTree(TreeNode root) {
        if (root == null) return true;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        boolean sawNull = false;

        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (node == null) {
                sawNull = true;
            } else {
                if (sawNull) return false;
                q.offer(node.left);
                q.offer(node.right);
            }
        }
        return true;
    }
}