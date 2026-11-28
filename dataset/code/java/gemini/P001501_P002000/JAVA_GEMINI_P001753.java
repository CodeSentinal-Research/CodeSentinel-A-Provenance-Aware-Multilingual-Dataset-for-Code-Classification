class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxDepth = -1, res = -1;

    private void dfs(TreeNode node, int depth) {
        if (node == null) return;
        if (node.left != null || node.right != null) {
            if (depth > maxDepth) {
                maxDepth = depth;
                res = node.val;
            }
        }
        dfs(node.left, depth + 1);
        dfs(node.right, depth + 1);
    }

    public int lowestInternalNode(TreeNode root) {
        maxDepth = -1;
        res = -1;
        dfs(root, 0);
        return res;
    }
}