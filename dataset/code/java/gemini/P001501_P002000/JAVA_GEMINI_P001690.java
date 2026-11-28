class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxSum = 0;

    static class SubtreeInfo {
        boolean isBST;
        int minVal, maxVal, sum;
        SubtreeInfo(boolean isBST, int minVal, int maxVal, int sum) {
            this.isBST = isBST;
            this.minVal = minVal;
            this.maxVal = maxVal;
            this.sum = sum;
        }
    }

    private SubtreeInfo dfs(TreeNode node) {
        if (node == null) return new SubtreeInfo(true, Integer.MAX_VALUE, Integer.MIN_VALUE, 0);

        SubtreeInfo l = dfs(node.left);
        SubtreeInfo r = dfs(node.right);

        if (l.isBST && r.isBST && l.maxVal < node.val && node.val < r.minVal) {
            int curSum = l.sum + r.sum + node.val;
            maxSum = Math.max(maxSum, curSum);
            return new SubtreeInfo(true, Math.min(l.minVal, node.val), Math.max(r.maxVal, node.val), curSum);
        }

        return new SubtreeInfo(false, 0, 0, 0);
    }

    public int maxSumBST(TreeNode root) {
        maxSum = 0;
        dfs(root);
        return maxSum;
    }
}