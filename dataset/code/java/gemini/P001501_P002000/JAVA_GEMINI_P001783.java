class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int centroid = -1;
    private int totalNodes = 0;

    private int countNodes(TreeNode node) {
        if (node == null) return 0;
        return 1 + countNodes(node.left) + countNodes(node.right);
    }

    private int dfs(TreeNode node) {
        if (node == null) return 0;
        int l = dfs(node.left);
        int r = dfs(node.right);
        int parentSize = totalNodes - (1 + l + r);

        if (l <= totalNodes / 2 && r <= totalNodes / 2 && parentSize <= totalNodes / 2) {
            centroid = node.val;
        }

        return 1 + l + r;
    }

    public int findCentroid(TreeNode root) {
        centroid = -1;
        totalNodes = countNodes(root);
        dfs(root);
        return centroid;
    }
}