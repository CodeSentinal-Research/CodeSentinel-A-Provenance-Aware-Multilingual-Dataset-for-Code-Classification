class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int ans = 0;

    private int dfs(TreeNode node, int k) {
        if (node == null) return 0;
        int desc = dfs(node.left, k) + dfs(node.right, k);
        if (desc == k) ans++;
        return desc + 1;
    }

    public int countNodesWithKDescendants(TreeNode root, int k) {
        ans = 0;
        dfs(root, k);
        return ans;
    }
}