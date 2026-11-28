class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxPath = 0;

    private int dfs(TreeNode node) {
        if (node == null) return 0;
        int lLen = dfs(node.left);
        int rLen = dfs(node.right);

        int lArrow = (node.left != null && node.left.val == node.val) ? lLen + 1 : 0;
        int rArrow = (node.right != null && node.right.val == node.val) ? rLen + 1 : 0;

        maxPath = Math.max(maxPath, lArrow + rArrow);
        return Math.max(lArrow, rArrow);
    }

    public int longestUnivaluePath(TreeNode root) {
        maxPath = 0;
        dfs(root);
        return maxPath;
    }
}