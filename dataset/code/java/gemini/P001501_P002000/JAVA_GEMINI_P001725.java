class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int pathSum(TreeNode root, int targetSum) {
        if (root == null) return 0;
        if (root.left == null && root.right == null) return root.val == targetSum ? 1 : 0;
        return pathSum(root.left, targetSum - root.val) + pathSum(root.right, targetSum - root.val);
    }
}