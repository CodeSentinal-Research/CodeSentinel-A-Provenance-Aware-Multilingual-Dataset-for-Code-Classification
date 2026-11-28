class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public void convertTree(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) return;

        int childSum = (root.left != null ? root.left.val : 0) + (root.right != null ? root.right.val : 0);
        if (childSum >= root.val) {
            root.val = childSum;
        } else {
            if (root.left != null) root.left.val = root.val;
            if (root.right != null) root.right.val = root.val;
        }

        convertTree(root.left);
        convertTree(root.right);

        int tot = (root.left != null ? root.left.val : 0) + (root.right != null ? root.right.val : 0);
        if (root.left != null || root.right != null) {
            root.val = tot;
        }
    }
}