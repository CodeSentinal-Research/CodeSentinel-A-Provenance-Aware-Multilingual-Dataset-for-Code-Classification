class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int convert(TreeNode node) {
        if (node == null) return 0;
        int oldVal = node.val;
        int lSum = convert(node.left);
        int rSum = convert(node.right);
        node.val = lSum + rSum;
        return node.val + oldVal;
    }

    public void toSumTree(TreeNode root) {
        convert(root);
    }
}