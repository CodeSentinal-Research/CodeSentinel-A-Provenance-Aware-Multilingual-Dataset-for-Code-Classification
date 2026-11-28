class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private long prev = Long.MIN_VALUE;
    private boolean possible = true;

    private void inorder(TreeNode node) {
        if (node == null || !possible) return;
        inorder(node.left);
        if (node.val <= prev) {
            possible = false;
            return;
        }
        prev = node.val;
        inorder(node.right);
    }

    public boolean canBeBSTByRotations(TreeNode root) {
        prev = Long.MIN_VALUE;
        possible = true;
        inorder(root);
        return possible;
    }
}