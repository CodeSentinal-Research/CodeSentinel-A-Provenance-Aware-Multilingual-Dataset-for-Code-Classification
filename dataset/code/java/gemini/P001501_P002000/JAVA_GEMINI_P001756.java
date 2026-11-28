class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public boolean everyLeafHasSibling(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) return true;
        if (root.left != null && root.right == null && root.left.left == null && root.left.right == null) return false;
        if (root.right != null && root.left == null && root.right.left == null && root.right.right == null) return false;
        return everyLeafHasSibling(root.left) && everyLeafHasSibling(root.right);
    }
}