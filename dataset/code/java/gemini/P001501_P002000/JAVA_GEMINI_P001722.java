class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int dfs(TreeNode node, int level) {
        if (node == null) return 0;
        int cur = level % 2 == 0 ? node.val : 0;
        return cur + dfs(node.left, level + 1) + dfs(node.right, level + 1);
    }

    public int sumEvenLevels(TreeNode root) {
        return dfs(root, 1);
    }
}