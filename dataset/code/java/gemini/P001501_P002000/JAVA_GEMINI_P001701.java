import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public TreeNode replaceValueInTree(TreeNode root) {
        if (root == null) return null;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        root.val = 0;

        while (!q.isEmpty()) {
            int size = q.size();
            long levelSum = 0;
            List<TreeNode> current = new ArrayList<>(q);
            for (TreeNode node : current) {
                if (node.left != null) levelSum += node.left.val;
                if (node.right != null) levelSum += node.right.val;
            }

            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                int siblingSum = (node.left != null ? node.left.val : 0) + (node.right != null ? node.right.val : 0);
                if (node.left != null) {
                    node.left.val = (int)(levelSum - siblingSum);
                    q.offer(node.left);
                }
                if (node.right != null) {
                    node.right.val = (int)(levelSum - siblingSum);
                    q.offer(node.right);
                }
            }
        }
        return root;
    }
}