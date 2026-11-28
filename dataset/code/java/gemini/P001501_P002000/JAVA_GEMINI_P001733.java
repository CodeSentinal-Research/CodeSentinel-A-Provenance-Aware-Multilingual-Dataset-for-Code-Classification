class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int check(TreeNode node) {
        if (node == null) return 0;
        if (node.left == null && node.right == null) return node.val;
        int lSum = check(node.left);
        int rSum = check(node.right);
        if (lSum == -1 || rSum == -1 || node.val != lSum + rSum) return -1;
        return node.val + lSum + rSum;
    }

    public boolean isSumTree(TreeNode root) {
        return check(root) != -1;
    }
}