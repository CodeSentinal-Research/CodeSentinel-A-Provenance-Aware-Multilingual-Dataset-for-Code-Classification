class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxSum = Integer.MIN_VALUE;

    private int gain(TreeNode node) {
        if (node == null) return 0;
        int leftGain = Math.max(0, gain(node.left));
        int rightGain = Math.max(0, gain(node.right));
        maxSum = Math.max(maxSum, node.val + leftGain + rightGain);
        return node.val + Math.max(leftGain, rightGain);
    }

    public int maxPathSum(TreeNode root) {
        maxSum = Integer.MIN_VALUE;
        gain(root);
        return maxSum;
    }
}