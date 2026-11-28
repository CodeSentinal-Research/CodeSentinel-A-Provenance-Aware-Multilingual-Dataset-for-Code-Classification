import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int firstNonFullNode(TreeNode root) {
        if (root == null) return -1;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (node.left == null || node.right == null) return node.val;
            q.offer(node.left);
            q.offer(node.right);
        }
        return -1;
    }
}