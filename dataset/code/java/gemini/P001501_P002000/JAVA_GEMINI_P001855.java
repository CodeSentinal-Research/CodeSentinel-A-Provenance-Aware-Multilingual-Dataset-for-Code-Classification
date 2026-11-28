class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int countNodes(TreeNode node) {
        if (node == null) return 0;
        return 1 + countNodes(node.left) + countNodes(node.right);
    }

    private int getHeight(TreeNode node) {
        if (node == null) return 0;
        return 1 + Math.max(getHeight(node.left), getHeight(node.right));
    }

    public int minInsertionsToCompleteBST(TreeNode root) {
        int n = countNodes(root);
        int h = getHeight(root);
        int minNodes = 1 << (h - 1);
        return Math.max(0, minNodes - n);
    }
}