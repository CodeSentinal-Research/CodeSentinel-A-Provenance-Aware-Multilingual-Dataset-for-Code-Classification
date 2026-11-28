class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public boolean checkChildrenSum(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) return true;
        int childSum = (root.left != null ? root.left.val : 0) + (root.right != null ? root.right.val : 0);
        if (root.val != childSum) return false;
        return checkChildrenSum(root.left) && checkChildrenSum(root.right);
    }
}