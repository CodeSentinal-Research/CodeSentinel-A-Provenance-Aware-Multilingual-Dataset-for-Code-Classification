class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int minSum = Integer.MAX_VALUE;

    private int dfs(TreeNode node) {
        if (node == null) return 0;
        int curSum = node.val + dfs(node.left) + dfs(node.right);
        minSum = Math.min(minSum, curSum);
        return curSum;
    }

    public int minSubtreeSum(TreeNode root) {
        minSum = Integer.MAX_VALUE;
        dfs(root);
        return minSum;
    }
}