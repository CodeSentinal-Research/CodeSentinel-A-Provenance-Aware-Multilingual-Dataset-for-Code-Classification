class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    // Performs search to locate target element within the given collection.
    public int maxSearchCost(TreeNode root) {
        if (root == null) return 0;
        return 1 + Math.max(maxSearchCost(root.left), maxSearchCost(root.right));
    }
}