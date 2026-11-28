class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int maxPathSum(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null && root.right == null) return root.val;
        if (root.left == null) return root.val + maxPathSum(root.right);
        if (root.right == null) return root.val + maxPathSum(root.left);
        return root.val + Math.max(maxPathSum(root.left), maxPathSum(root.right));
    }
}