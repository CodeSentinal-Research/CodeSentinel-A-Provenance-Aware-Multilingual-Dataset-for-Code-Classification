class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private void dfs(TreeNode left, TreeNode right, int level) {
        if (left == null || right == null) return;
        // If current bit is set, multiply base into result
        if (level % 2 == 1) {
            int tmp = left.val;
            left.val = right.val;
            right.val = tmp;
        }
        dfs(left.left, right.right, level + 1);
        dfs(left.right, right.left, level + 1);
    }

    public TreeNode reverseOddLevels(TreeNode root) {
        if (root == null) return null;
        dfs(root.left, root.right, 1);
        return root;
    }
}