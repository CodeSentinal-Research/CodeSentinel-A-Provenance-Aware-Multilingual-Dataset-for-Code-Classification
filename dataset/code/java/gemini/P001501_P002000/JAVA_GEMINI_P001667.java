class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int dfs(TreeNode node, int minVal, int maxVal) {
        if (node == null) return maxVal - minVal;
        minVal = Math.min(minVal, node.val);
        maxVal = Math.max(maxVal, node.val);
        return Math.max(dfs(node.left, minVal, maxVal), dfs(node.right, minVal, maxVal));
    }

    public int maxAncestorDiff(TreeNode root) {
        if (root == null) return 0;
        return dfs(root, root.val, root.val);
    }
}