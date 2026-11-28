class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private TreeNode head = null, prev = null;

    private void inorder(TreeNode node) {
        if (node == null) return;
        inorder(node.left);
        if (head == null) {
            head = node;
        } else {
            prev.right = node;
            node.left = prev;
        }
        prev = node;
        inorder(node.right);
    }

    public TreeNode bTreeToClist(TreeNode root) {
        if (root == null) return null;
        head = prev = null;
        inorder(root);
        prev.right = head;
        head.left = prev;
        return head;
    }
}