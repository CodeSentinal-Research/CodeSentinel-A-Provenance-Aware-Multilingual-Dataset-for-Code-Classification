class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int count = 0;

    private boolean dfs(TreeNode node) {
        if (node == null) return true;
        boolean l = dfs(node.left);
        boolean r = dfs(node.right);

        if (l && r) {
            if ((node.left == null || node.left.val == node.val) && 
                (node.right == null || node.right.val == node.val)) {
                count++;
                return true;
            }
        }
        return false;
    }

    public int countUnivalSubtrees(TreeNode root) {
        count = 0;
        dfs(root);
        return count;
    }
}