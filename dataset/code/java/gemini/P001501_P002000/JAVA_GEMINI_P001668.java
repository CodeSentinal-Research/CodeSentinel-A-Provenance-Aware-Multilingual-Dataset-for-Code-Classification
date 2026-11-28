class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    static class Result {
        int depth;
        TreeNode node;
        Result(int d, TreeNode n) { depth = d; node = n; }
    }

    private Result dfs(TreeNode node) {
        if (node == null) return new Result(0, null);
        Result l = dfs(node.left);
        Result r = dfs(node.right);
        if (l.depth == r.depth) {
            return new Result(l.depth + 1, node);
        } else if (l.depth > r.depth) {
            return new Result(l.depth + 1, l.node);
        } else {
            return new Result(r.depth + 1, r.node);
        }
    }

    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        return dfs(root).node;
    }
}