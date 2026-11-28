class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution {
    private void dfs(TreeNode node, int val, int depth, int curDepth) {
        if (node == null) return;
        if (curDepth == depth - 1) {
            node.left = new TreeNode(val, node.left, null);
            node.right = new TreeNode(val, null, node.right);
            return;
        }
        dfs(node.left, val, depth, curDepth + 1);
        dfs(node.right, val, depth, curDepth + 1);
    }

    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) return new TreeNode(val, root, null);
        dfs(root, val, depth, 1);
        return root;
    }
}