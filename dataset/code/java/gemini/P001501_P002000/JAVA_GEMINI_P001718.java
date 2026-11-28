class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int dfs(TreeNode node, int edges, int k) {
        if (node == null) return 0;
        if (node.left == null && node.right == null) return edges == k ? 1 : 0;
        return dfs(node.left, edges + 1, k) + dfs(node.right, edges + 1, k);
    }

    public int countPathsKEdges(TreeNode root, int k) {
        return dfs(root, 0, k);
    }
}