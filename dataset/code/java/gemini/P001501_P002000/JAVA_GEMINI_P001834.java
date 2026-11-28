class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private boolean dfs(TreeNode node, int low, int high) {
        if (node == null) return false;
        if (low == high) return true;
        return dfs(node.left, low, node.val - 1) || dfs(node.right, node.val + 1, high);
    }

    public boolean isDeadEnd(TreeNode root) {
        return dfs(root, 1, Integer.MAX_VALUE);
    }
}