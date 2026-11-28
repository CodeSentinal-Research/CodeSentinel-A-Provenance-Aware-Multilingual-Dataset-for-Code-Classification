class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int dfs(TreeNode node) {
        if (node == null) return 0;
        int lSum = dfs(node.left);
        int rSum = dfs(node.right);
        int oldVal = node.val;
        node.val = lSum + rSum;
        return node.val + oldVal;
    }

    public TreeNode convertToDescendantSum(TreeNode root) {
        dfs(root);
        return root;
    }
}