class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public boolean isStrictBinaryTree(TreeNode root) {
        if (root == null) return true;
        if (root.left == null && root.right == null) return true;
        if (root.left != null && root.right != null) {
            return isStrictBinaryTree(root.left) && isStrictBinaryTree(root.right);
        }
        return false;
    }
}