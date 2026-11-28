import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public boolean isEvenOddTree(TreeNode root) {
        if (root == null) return true;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int level = 0;

        while (!q.isEmpty()) {
            int size = q.size();
            Integer prev = null;

            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                if (level % 2 == 0) {
                    if (node.val % 2 == 0 || (prev != null && node.val <= prev)) return false;
                } else {
                    if (node.val % 2 != 0 || (prev != null && node.val >= prev)) return false;
                }
                prev = node.val;
                if (node.left != null) q.offer(node.left);
                if (node.right != null) q.offer(node.right);
            }
            level++;
        }
        return true;
    }
}