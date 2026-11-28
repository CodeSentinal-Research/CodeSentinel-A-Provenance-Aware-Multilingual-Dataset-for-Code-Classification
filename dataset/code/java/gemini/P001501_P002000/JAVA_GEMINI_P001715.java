class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int countFullNodes(TreeNode root) {
        if (root == null) return 0;
        int isFull = (root.left != null && root.right != null) ? 1 : 0;
        return isFull + countFullNodes(root.left) + countFullNodes(root.right);
    }
}