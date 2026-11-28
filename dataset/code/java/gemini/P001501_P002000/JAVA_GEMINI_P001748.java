class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int countInternalNodes(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) return 0;
        return 1 + countInternalNodes(root.left) + countInternalNodes(root.right);
    }
}