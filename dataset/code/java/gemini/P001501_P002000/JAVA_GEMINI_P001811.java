class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxSize = 0;

    static class Result {
        boolean isBST;
        int size, minVal, maxVal;
        Result(boolean isBST, int size, int minVal, int maxVal) {
            this.isBST = isBST;
            this.size = size;
            this.minVal = minVal;
            this.maxVal = maxVal;
        }
    }

    private Result dfs(TreeNode node) {
        if (node == null) return new Result(true, 0, Integer.MAX_VALUE, Integer.MIN_VALUE);

        Result l = dfs(node.left);
        Result r = dfs(node.right);

        if (l.isBST && r.isBST && l.maxVal < node.val && node.val < r.minVal) {
            int curSize = l.size + r.size + 1;
            maxSize = Math.max(maxSize, curSize);
            return new Result(true, curSize, Math.min(l.minVal, node.val), Math.max(r.maxVal, node.val));
        }

        return new Result(false, 0, 0, 0);
    }

    public int largestBSTSubtree(TreeNode root) {
        maxSize = 0;
        dfs(root);
        return maxSize;
    }
}