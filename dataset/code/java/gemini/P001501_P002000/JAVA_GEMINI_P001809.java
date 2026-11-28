class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int curSum = 0;

    private void reverseInorder(TreeNode node) {
        if (node == null) return;
        reverseInorder(node.right);
        curSum += node.val;
        node.val = curSum;
        reverseInorder(node.left);
    }

    public TreeNode bstToGst(TreeNode root) {
        curSum = 0;
        reverseInorder(root);
        return root;
    }
}