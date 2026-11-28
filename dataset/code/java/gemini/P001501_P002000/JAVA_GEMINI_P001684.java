class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public boolean isSiblings(TreeNode root, int a, int b) {
        if (root == null) return false;
        if (root.left != null && root.right != null) {
            if ((root.left.val == a && root.right.val == b) || (root.left.val == b && root.right.val == a)) {
                return true;
            }
        }
        return isSiblings(root.left, a, b) || isSiblings(root.right, a, b);
    }
}