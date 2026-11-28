class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxDepth = -1, res = 0;

    private void dfs(TreeNode node, int depth) {
        if (node == null) return;
        if (depth > maxDepth) {
            maxDepth = depth;
            res = node.val;
        }
        dfs(node.right, depth + 1);
        dfs(node.left, depth + 1);
    }

    public int findBottomRightValue(TreeNode root) {
        maxDepth = -1;
        res = root.val;
        dfs(root, 0);
        return res;
    }
}