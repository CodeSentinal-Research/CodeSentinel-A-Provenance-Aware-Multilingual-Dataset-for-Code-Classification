class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxSize = 0;

    static class Result {
        boolean isFree;
        int size;
        Result(boolean f, int s) { isFree = f; size = s; }
    }

    private Result dfs(TreeNode node, int low, int high) {
        if (node == null) return new Result(true, 0);
        if (low == high) return new Result(false, 0);

        Result l = dfs(node.left, low, node.val - 1);
        Result r = dfs(node.right, node.val + 1, high);

        if (l.isFree && r.isFree) {
            int curSize = l.size + r.size + 1;
            maxSize = Math.max(maxSize, curSize);
            return new Result(true, curSize);
        }

        return new Result(false, 0);
    }

    public int largestDeadEndFreeSubtree(TreeNode root) {
        maxSize = 0;
        dfs(root, 1, Integer.MAX_VALUE);
        return maxSize;
    }
}