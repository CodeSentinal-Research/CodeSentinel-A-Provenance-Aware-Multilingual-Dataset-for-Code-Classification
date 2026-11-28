class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int cameras = 0;

    private int dfs(TreeNode node) {
        if (node == null) return 2;
        int l = dfs(node.left);
        int r = dfs(node.right);

        if (l == 0 || r == 0) {
            cameras++;
            return 1;
        }
        if (l == 1 || r == 1) return 2;
        return 0;
    }

    public int minCameraCover(TreeNode root) {
        cameras = 0;
        if (dfs(root) == 0) cameras++;
        return cameras;
    }
}