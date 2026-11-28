class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int dfs(TreeNode node, int curVal) {
        if (node == null) return 0;
        curVal = (curVal << 1) | node.val;
        if (node.left == null && node.right == null) return curVal;
        return dfs(node.left, curVal) + dfs(node.right, curVal);
    }

    public int sumRootToLeaf(TreeNode root) {
        return dfs(root, 0);
    }
}