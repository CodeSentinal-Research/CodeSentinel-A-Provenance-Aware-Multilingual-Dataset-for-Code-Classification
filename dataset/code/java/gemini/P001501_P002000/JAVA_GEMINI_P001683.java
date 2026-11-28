class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxDepth = -1;
    private int res = -1;

    private void dfs(TreeNode node, int depth, boolean isLeft) {
        if (node == null) return;
        if (isLeft && node.left == null && node.right == null) {
            if (depth > maxDepth) {
                maxDepth = depth;
                res = node.val;
            }
        }
        dfs(node.left, depth + 1, true);
        dfs(node.right, depth + 1, false);
    }

    public int deepestLeftLeaf(TreeNode root) {
        maxDepth = -1;
        res = -1;
        dfs(root, 0, false);
        return res;
    }
}