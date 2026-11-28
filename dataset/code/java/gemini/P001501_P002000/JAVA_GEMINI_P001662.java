class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int check(TreeNode node) {
        if (node == null) return 0;
        int l = check(node.left);
        if (l == -1) return -1;
        int r = check(node.right);
        if (r == -1 || Math.abs(l - r) > 1) return -1;
        return 1 + Math.max(l, r);
    }

    public boolean isBalanced(TreeNode root) {
        return check(root) != -1;
    }
}