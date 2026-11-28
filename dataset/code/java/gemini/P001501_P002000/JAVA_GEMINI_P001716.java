class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int minDepth = Integer.MAX_VALUE;
    private int res = -1;

    private void dfs(TreeNode node, int depth) {
        if (node == null) return;
        if (node.left == null && node.right == null) {
            if (depth < minDepth) {
                minDepth = depth;
                res = node.val;
            }
            return;
        }
        dfs(node.left, depth + 1);
        dfs(node.right, depth + 1);
    }

    public int lowestLeaf(TreeNode root) {
        minDepth = Integer.MAX_VALUE;
        res = -1;
        dfs(root, 1);
        return res;
    }
}