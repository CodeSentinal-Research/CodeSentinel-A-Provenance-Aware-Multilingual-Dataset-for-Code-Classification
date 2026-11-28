class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int minDepth = Integer.MAX_VALUE, res = -1;

    private TreeNode lca(TreeNode node, int p, int q) {
        if (node == null || node.val == p || node.val == q) return node;
        TreeNode l = lca(node.left, p, q);
        TreeNode r = lca(node.right, p, q);
        if (l != null && r != null) return node;
        return l != null ? l : r;
    }

    private void findLeaf(TreeNode node, int depth) {
        if (node == null) return;
        if (node.left == null && node.right == null) {
            if (depth < minDepth) {
                minDepth = depth;
                res = node.val;
            }
            return;
        }
        findLeaf(node.left, depth + 1);
        findLeaf(node.right, depth + 1);
    }

    public int nearestCommonLeaf(TreeNode root, int p, int q) {
        TreeNode ancestor = lca(root, p, q);
        minDepth = Integer.MAX_VALUE;
        res = -1;
        findLeaf(ancestor, 0);
        return res;
    }
}