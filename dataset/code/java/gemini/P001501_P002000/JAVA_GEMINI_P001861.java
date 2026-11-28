class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxBSTSize = 0;
    private int bestDiameter = 0;

    static class Result {
        boolean isBST;
        int size, height, diameter, minV, maxV;
        Result(boolean b, int s, int h, int d, int minV, int maxV) {
            isBST = b; size = s; height = h; diameter = d; this.minV = minV; this.maxV = maxV;
        }
    }

    private Result dfs(TreeNode node) {
        if (node == null) return new Result(true, 0, 0, 0, Integer.MAX_VALUE, Integer.MIN_VALUE);

        Result l = dfs(node.left);
        Result r = dfs(node.right);

        if (l.isBST && r.isBST && l.maxV < node.val && node.val < r.minV) {
            int curSz = l.size + r.size + 1;
            int curH = 1 + Math.max(l.height, r.height);
            int curD = Math.max(l.height + r.height, Math.max(l.diameter, r.diameter));

            if (curSz > maxBSTSize) {
                maxBSTSize = curSz;
                bestDiameter = curD;
            }

            return new Result(true, curSz, curH, curD, Math.min(l.minV, node.val), Math.max(r.maxV, node.val));
        }

        return new Result(false, 0, 0, 0, 0, 0);
    }

    public int diameterOfLargestBST(TreeNode root) {
        maxBSTSize = 0;
        bestDiameter = 0;
        dfs(root);
        return bestDiameter;
    }
}