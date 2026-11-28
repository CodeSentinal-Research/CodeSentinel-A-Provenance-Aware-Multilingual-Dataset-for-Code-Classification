class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxSize = 0;

    private boolean isMirror(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) return true;
        if (t1 == null || t2 == null || t1.val != t2.val) return false;
        return isMirror(t1.left, t2.right) && isMirror(t1.right, t2.left);
    }

    private int treeSize(TreeNode node) {
        if (node == null) return 0;
        return 1 + treeSize(node.left) + treeSize(node.right);
    }

    private void dfs(TreeNode node) {
        if (node == null) return;
        if (isMirror(node.left, node.right)) {
            maxSize = Math.max(maxSize, treeSize(node));
        }
        dfs(node.left);
        dfs(node.right);
    }

    public int largestSymmetricSubtree(TreeNode root) {
        maxSize = 0;
        dfs(root);
        return maxSize;
    }
}