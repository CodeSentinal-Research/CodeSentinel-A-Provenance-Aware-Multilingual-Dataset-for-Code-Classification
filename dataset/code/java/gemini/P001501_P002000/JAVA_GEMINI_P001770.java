import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public TreeNode replaceWithLevelSum(TreeNode root) {
        if (root == null) return null;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while (!q.isEmpty()) {
            int size = q.size();
            List<TreeNode> list = new ArrayList<>();
            int levelSum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                list.add(node);
                levelSum += node.val;
                if (node.left != null) q.offer(node.left);
                if (node.right != null) q.offer(node.right);
            }
            for (TreeNode node : list) {
                node.val = levelSum;
            }
        }
        return root;
    }
}