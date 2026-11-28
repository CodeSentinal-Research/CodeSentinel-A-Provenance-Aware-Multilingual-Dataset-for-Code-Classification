class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public boolean isStructurallyIdentical(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null) return false;
        return isStructurallyIdentical(root1.left, root2.left) &&
               isStructurallyIdentical(root1.right, root2.right);
    }
}