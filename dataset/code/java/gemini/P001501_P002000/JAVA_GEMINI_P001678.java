class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private TreeNode xParent = null, yParent = null;
    private int xDepth = -1, yDepth = -1;

    private void dfs(TreeNode node, TreeNode parent, int depth, int x, int y) {
        if (node == null) return;
        if (node.val == x) {
            xParent = parent;
            xDepth = depth;
        } else if (node.val == y) {
            yParent = parent;
            yDepth = depth;
        }
        dfs(node.left, node, depth + 1, x, y);
        dfs(node.right, node, depth + 1, x, y);
    }

    public boolean isCousins(TreeNode root, int x, int y) {
        dfs(root, null, 0, x, y);
        return xDepth == yDepth && xParent != yParent;
    }
}