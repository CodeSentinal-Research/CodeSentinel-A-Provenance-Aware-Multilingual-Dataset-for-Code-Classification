class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxSize = 0;

    private int dfs(TreeNode node) {
        if (node == null) return 0;
        int l = dfs(node.left);
        int r = dfs(node.right);

        if (l != -1 && r != -1 && l == r) {
            int depth = l + 1;
            int size = (1 << depth) - 1;
            maxSize = Math.max(maxSize, size);
            return depth;
        }

        return -1;
    }

    public int largestPerfectSubtree(TreeNode root) {
        maxSize = 0;
        dfs(root);
        return maxSize;
    }
}