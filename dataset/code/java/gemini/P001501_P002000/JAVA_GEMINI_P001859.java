class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxSize = 0;

    static class Result {
        boolean isBST, isPerf;
        int height, minV, maxV;
        Result(boolean b, boolean p, int h, int minV, int maxV) {
            isBST = b; isPerf = p; height = h; this.minV = minV; this.maxV = maxV;
        }
    }

    private Result dfs(TreeNode node) {
        if (node == null) return new Result(true, true, 0, Integer.MAX_VALUE, Integer.MIN_VALUE);

        Result l = dfs(node.left);
        Result r = dfs(node.right);

        boolean isBST = l.isBST && r.isBST && l.maxV < node.val && node.val < r.minV;
        int minV = Math.min(l.minV, node.val);
        int maxV = Math.max(r.maxV, node.val);

        if (isBST && l.isPerf && r.isPerf && l.height == r.height) {
            int curH = l.height + 1;
            int size = (1 << curH) - 1;
            maxSize = Math.max(maxSize, size);
            return new Result(true, true, curH, minV, maxV);
        }

        return new Result(false, false, 0, 0, 0);
    }

    public int largestPerfectBSTSubtree(TreeNode root) {
        maxSize = 0;
        dfs(root);
        return maxSize;
    }
}