class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public TreeNode removeHalfNodes(TreeNode root) {
        if (root == null) return null;
        root.left = removeHalfNodes(root.left);
        root.right = removeHalfNodes(root.right);

        if (root.left == null && root.right == null) return root;
        if (root.left == null) return root.right;
        if (root.right == null) return root.left;

        return root;
    }
}