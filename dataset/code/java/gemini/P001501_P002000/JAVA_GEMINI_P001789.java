class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private boolean dfs(TreeNode node, Long low, Long high) {
        if (node == null) return true;
        if (node.val <= low || node.val >= high) return false;
        return dfs(node.left, low, (long)node.val) && dfs(node.right, (long)node.val, high);
    }

    public boolean isValidBST(TreeNode root) {
        return dfs(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}