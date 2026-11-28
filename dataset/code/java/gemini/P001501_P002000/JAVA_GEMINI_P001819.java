class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int rank = 0;

    private boolean inorder(TreeNode node, int key) {
        if (node == null) return false;
        if (inorder(node.left, key)) return true;
        if (node.val == key) {
            rank++;
            return true;
        }
        if (node.val < key) rank++;
        return inorder(node.right, key);
    }

    public int rankOfKey(TreeNode root, int key) {
        rank = 0;
        boolean found = inorder(root, key);
        return found ? rank : -1;
    }
}