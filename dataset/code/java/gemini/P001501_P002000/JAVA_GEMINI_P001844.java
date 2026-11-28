class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxSize = 0;

    static class Result {
        boolean isBST, isComp, isPerf;
        int height, size, minV, maxV;
        Result(boolean b, boolean c, boolean p, int h, int s, int minV, int maxV) {
            isBST = b; isComp = c; isPerf = p; height = h; size = s;
            this.minV = minV; this.maxV = maxV;
        }
    }

    private Result dfs(TreeNode node) {
        if (node == null) return new Result(true, true, true, 0, 0, Integer.MAX_VALUE, Integer.MIN_VALUE);

        Result l = dfs(node.left);
        Result r = dfs(node.right);

        boolean isBST = l.isBST && r.isBST && l.maxV < node.val && node.val < r.minV;
        int curSz = l.size + r.size + 1;
        int minV = Math.min(l.minV, node.val);
        int maxV = Math.max(r.maxV, node.val);

        if (isBST) {
            if (l.isPerf && r.isComp && l.height == r.height) {
                maxSize = Math.max(maxSize, curSz);
                return new Result(true, true, r.isPerf, l.height + 1, curSz, minV, maxV);
            }
            if (l.isComp && r.isPerf && l.height == r.height + 1) {
                maxSize = Math.max(maxSize, curSz);
                return new Result(true, true, false, l.height + 1, curSz, minV, maxV);
            }
        }

        return new Result(false, false, false, 0, 0, 0, 0);
    }

    public int largestCompleteBSTSubtree(TreeNode root) {
        maxSize = 0;
        dfs(root);
        return maxSize;
    }
}