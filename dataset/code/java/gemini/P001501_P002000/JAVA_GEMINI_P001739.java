class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public TreeNode removeLeaves(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) return null;
        root.left = removeLeaves(root.left);
        root.right = removeLeaves(root.right);
        return root;
    }
}