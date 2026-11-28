class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public boolean everyInternalNodeOneChild(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) return true;
        if (root.left != null && root.right != null) return false;
        return everyInternalNodeOneChild(root.left != null ? root.left : root.right);
    }
}