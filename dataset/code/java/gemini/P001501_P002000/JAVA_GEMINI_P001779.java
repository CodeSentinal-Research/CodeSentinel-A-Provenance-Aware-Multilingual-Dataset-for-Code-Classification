class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxLen = 0;

    private void dfs(TreeNode node, Integer parentVal, int curLen) {
        if (node == null) return;
        if (parentVal == null || node.val > parentVal) {
            curLen++;
        } else {
            curLen = 1;
        }
        maxLen = Math.max(maxLen, curLen);
        dfs(node.left, node.val, curLen);
        dfs(node.right, node.val, curLen);
    }

    public int longestIncreasingPath(TreeNode root) {
        maxLen = 0;
        dfs(root, null, 0);
        return maxLen;
    }
}