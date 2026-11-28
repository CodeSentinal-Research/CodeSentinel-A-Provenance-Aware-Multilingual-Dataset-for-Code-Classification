import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int minNodesLevel(TreeNode root) {
        if (root == null) return 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int minNodes = Integer.MAX_VALUE, minLevel = 1, curLevel = 1;

        while (!q.isEmpty()) {
            int size = q.size();
            if (size < minNodes) {
                minNodes = size;
                minLevel = curLevel;
            }
            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                if (node.left != null) q.offer(node.left);
                if (node.right != null) q.offer(node.right);
            }
            curLevel++;
        }
        return minLevel;
    }
}