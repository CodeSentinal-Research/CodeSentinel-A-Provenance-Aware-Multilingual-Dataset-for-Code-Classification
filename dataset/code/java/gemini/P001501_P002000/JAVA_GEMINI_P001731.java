class TreeNode {
    int val;
    TreeNode left, right;
    boolean isThreaded;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private TreeNode prev = null;

    private void inorder(TreeNode node) {
        if (node == null) return;
        inorder(node.left);
        if (prev != null && prev.right == null) {
            prev.right = node;
            prev.isThreaded = true;
        }
        prev = node;
        inorder(node.right);
    }

    public TreeNode convertToThreaded(TreeNode root) {
        prev = null;
        inorder(root);
        return root;
    }
}