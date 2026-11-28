import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int levelOrderSuccessor(TreeNode root, int targetVal) {
        if (root == null) return -1;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        boolean found = false;

        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (found) return node.val;
            if (node.val == targetVal) found = true;
            if (node.left != null) q.offer(node.left);
            if (node.right != null) q.offer(node.right);
        }
        return -1;
    }
}