class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private TreeNode insert(TreeNode node, int val) {
        if (node == null) return new TreeNode(val);
        if (val < node.val) node.left = insert(node.left, val);
        else node.right = insert(node.right, val);
        return node;
    }

    private void addAll(TreeNode root1, TreeNode node) {
        if (node == null) return;
        insert(root1, node.val);
        addAll(root1, node.left);
        addAll(root1, node.right);
    }

    public TreeNode joinBST(TreeNode root1, TreeNode root2) {
        if (root1 == null) return root2;
        if (root2 == null) return root1;
        addAll(root1, root2);
        return root1;
    }
}