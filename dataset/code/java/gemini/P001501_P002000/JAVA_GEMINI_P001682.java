class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private Integer leafLevel = null;

    private boolean dfs(TreeNode node, int level) {
        if (node == null) return true;
        if (node.left == null && node.right == null) {
            if (leafLevel == null) {
                leafLevel = level;
                return true;
            }
            return leafLevel == level;
        }
        return dfs(node.left, level + 1) && dfs(node.right, level + 1);
    }

    public boolean checkLeavesSameLevel(TreeNode root) {
        leafLevel = null;
        return dfs(root, 0);
    }
}