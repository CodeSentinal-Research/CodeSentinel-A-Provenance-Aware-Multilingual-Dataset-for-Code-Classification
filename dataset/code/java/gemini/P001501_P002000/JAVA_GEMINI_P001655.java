class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private TreeNode first = null, last = null;

    private void inorder(TreeNode node) {
        if (node == null) return;
        inorder(node.left);
        if (last != null) {
            last.right = node;
            node.left = last;
        } else {
            first = node;
        }
        last = node;
        inorder(node.right);
    }

    public TreeNode treeToDoublyList(TreeNode root) {
        if (root == null) return null;
        first = last = null;
        inorder(root);
        last.right = first;
        first.left = last;
        return first;
    }
}