class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int countHalfNodes(TreeNode root) {
        if (root == null) return 0;
        int isHalf = ((root.left != null && root.right == null) || (root.left == null && root.right != null)) ? 1 : 0;
        return isHalf + countHalfNodes(root.left) + countHalfNodes(root.right);
    }
}