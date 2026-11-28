class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public boolean isIsomorphic(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null || root1.val != root2.val) return false;
        return (isIsomorphic(root1.left, root2.left) && isIsomorphic(root1.right, root2.right)) ||
               (isIsomorphic(root1.left, root2.right) && isIsomorphic(root1.right, root2.left));
    }
}