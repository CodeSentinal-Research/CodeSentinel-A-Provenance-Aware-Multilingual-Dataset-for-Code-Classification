import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int levelOrderPredecessor(TreeNode root, int targetVal) {
        if (root == null) return -1;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int prevVal = -1;

        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (node.val == targetVal) return prevVal;
            prevVal = node.val;
            if (node.left != null) q.offer(node.left);
            if (node.right != null) q.offer(node.right);
        }
        return -1;
    }
}