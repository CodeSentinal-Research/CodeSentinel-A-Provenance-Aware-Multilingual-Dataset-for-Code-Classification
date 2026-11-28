class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int count = 0;

    private void dfs(TreeNode node, int low, int high) {
        if (node == null) return;
        if (low == high) {
            count++;
            return;
        }
        dfs(node.left, low, node.val - 1);
        dfs(node.right, node.val + 1, high);
    }

    public int countDeadEnds(TreeNode root) {
        count = 0;
        dfs(root, 1, Integer.MAX_VALUE);
        return count;
    }
}