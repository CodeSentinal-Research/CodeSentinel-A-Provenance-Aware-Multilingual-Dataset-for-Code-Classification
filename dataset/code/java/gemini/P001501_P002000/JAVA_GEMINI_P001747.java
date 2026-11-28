import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int maxLeafLevel(TreeNode root) {
        if (root == null) return 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int maxLeaves = -1, maxLevel = 1, curLevel = 1;

        while (!q.isEmpty()) {
            int size = q.size();
            int leafCount = 0;
            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                if (node.left == null && node.right == null) leafCount++;
                if (node.left != null) q.offer(node.left);
                if (node.right != null) q.offer(node.right);
            }
            if (leafCount > maxLeaves) {
                maxLeaves = leafCount;
                maxLevel = curLevel;
            }
            curLevel++;
        }
        return maxLevel;
    }
}