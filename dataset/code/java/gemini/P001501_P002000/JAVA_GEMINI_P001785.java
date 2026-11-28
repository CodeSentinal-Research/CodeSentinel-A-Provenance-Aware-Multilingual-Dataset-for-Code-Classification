class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int[] dfs(TreeNode node) {
        if (node == null) return new int[]{0, 0};
        int[] l = dfs(node.left);
        int[] r = dfs(node.right);

        int incl = 1 + l[1] + r[1];
        int excl = Math.max(l[0], l[1]) + Math.max(r[0], r[1]);
        return new int[]{incl, excl};
    }

    public int maxIndependentSet(TreeNode root) {
        int[] res = dfs(root);
        return Math.max(res[0], res[1]);
    }
}