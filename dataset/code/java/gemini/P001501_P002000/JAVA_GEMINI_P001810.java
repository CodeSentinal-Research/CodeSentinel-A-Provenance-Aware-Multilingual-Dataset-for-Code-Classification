class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int curSum = 0;

    private void inorder(TreeNode node) {
        if (node == null) return;
        inorder(node.left);
        curSum += node.val;
        node.val = curSum;
        inorder(node.right);
    }

    public TreeNode bstToCumulative(TreeNode root) {
        curSum = 0;
        inorder(root);
        return root;
    }
}