class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxLen = 0;

    private void dfs(TreeNode node, TreeNode parent, int length) {
        if (node == null) return;
        if (parent != null && node.val == parent.val + 1) {
            length++;
        } else {
            length = 1;
        }
        maxLen = Math.max(maxLen, length);
        dfs(node.left, node, length);
        dfs(node.right, node, length);
    }

    public int longestConsecutive(TreeNode root) {
        maxLen = 0;
        dfs(root, null, 0);
        return maxLen;
    }
}