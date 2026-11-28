class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int minPathSum(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null && root.right == null) return root.val;
        if (root.left == null) return root.val + minPathSum(root.right);
        if (root.right == null) return root.val + minPathSum(root.left);
        return root.val + Math.min(minPathSum(root.left), minPathSum(root.right));
    }
}