class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private Integer leafDepth = null;

    private boolean dfs(TreeNode node, int depth) {
        if (node == null) return true;
        if (node.left == null && node.right == null) {
            if (leafDepth == null) {
                leafDepth = depth;
                return true;
            }
            return leafDepth == depth;
        }
        return dfs(node.left, depth + 1) && dfs(node.right, depth + 1);
    }

    public boolean allPathsSameLength(TreeNode root) {
        leafDepth = null;
        return dfs(root, 0);
    }
}