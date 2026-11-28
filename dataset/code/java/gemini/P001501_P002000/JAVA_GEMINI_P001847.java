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

    public int minRotationsToBalance(TreeNode root) {
        int n = countNodes(root);
        if (n <= 2) return 0;

        int h = (int)(Math.log(n + 1) / Math.log(2));
        int m = (1 << h) - 1;
        int totalRotations = n - m;

        m /= 2;
        while (m > 0) {
            totalRotations += m;
            m /= 2;
        }
        return totalRotations;
    }
}