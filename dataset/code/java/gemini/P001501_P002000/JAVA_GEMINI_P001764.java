class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxSize = 0;

    static class Result {
        boolean isUnival;
        int size;
        Result(boolean u, int s) { isUnival = u; size = s; }
    }

    private Result dfs(TreeNode node) {
        if (node == null) return new Result(true, 0);
        Result l = dfs(node.left);
        Result r = dfs(node.right);

        if (l.isUnival && r.isUnival) {
            if ((node.left == null || node.left.val == node.val) &&
                (node.right == null || node.right.val == node.val)) {
                int curSize = l.size + r.size + 1;
                maxSize = Math.max(maxSize, curSize);
                return new Result(true, curSize);
            }
        }
        return new Result(false, 0);
    }

    public int largestUnivalueSubtree(TreeNode root) {
        maxSize = 0;
        dfs(root);
        return maxSize;
    }
}