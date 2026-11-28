class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int findDepth(TreeNode node) {
        int d = 0;
        while (node != null) {
            d++;
            node = node.left;
        }
        return d;
    }

    private boolean check(TreeNode node, int level, int d) {
        if (node == null) return true;
        if (node.left == null && node.right == null) return level == d;
        if (node.left == null || node.right == null) return false;
        return check(node.left, level + 1, d) && check(node.right, level + 1, d);
    }

    public boolean isPerfect(TreeNode root) {
        int d = findDepth(root);
        return check(root, 1, d);
    }
}