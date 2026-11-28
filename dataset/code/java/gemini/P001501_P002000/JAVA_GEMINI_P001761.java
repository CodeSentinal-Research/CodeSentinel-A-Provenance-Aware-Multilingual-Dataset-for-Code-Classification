class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxSum = Integer.MIN_VALUE;

    private int dfs(TreeNode node) {
        if (node == null) return 0;
        int curSum = node.val + dfs(node.left) + dfs(node.right);
        maxSum = Math.max(maxSum, curSum);
        return curSum;
    }

    public int maxSubtreeSum(TreeNode root) {
        maxSum = Integer.MIN_VALUE;
        dfs(root);
        return maxSum;
    }
}