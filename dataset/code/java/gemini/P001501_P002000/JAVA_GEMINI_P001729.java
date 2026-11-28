class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private TreeNode lca(TreeNode node, int p, int q) {
        if (node == null || node.val == p || node.val == q) return node;
        TreeNode l = lca(node.left, p, q);
        TreeNode r = lca(node.right, p, q);
        if (l != null && r != null) return node;
        return l != null ? l : r;
    }

    private int dist(TreeNode node, int target) {
        if (node == null) return -1;
        if (node.val == target) return 0;
        int d = dist(node.left, target);
        if (d >= 0) return d + 1;
        d = dist(node.right, target);
        if (d >= 0) return d + 1;
        return -1;
    }

    public int findDistance(TreeNode root, int p, int q) {
        if (p == q) return 0;
        TreeNode ancestor = lca(root, p, q);
        return dist(ancestor, p) + dist(ancestor, q);
    }
}