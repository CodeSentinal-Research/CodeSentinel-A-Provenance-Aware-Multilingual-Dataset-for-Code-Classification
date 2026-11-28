class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int dfs(TreeNode node, int maxVal) {
        if (node == null) return 0;
        int good = node.val >= maxVal ? 1 : 0;
        int newMax = Math.max(maxVal, node.val);
        return good + dfs(node.left, newMax) + dfs(node.right, newMax);
    }

    public int goodNodes(TreeNode root) {
        return dfs(root, root.val);
    }
}