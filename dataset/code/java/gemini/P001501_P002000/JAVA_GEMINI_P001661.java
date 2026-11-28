class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private boolean isFoldableMirror(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) return true;
        if (t1 == null || t2 == null) return false;
        return isFoldableMirror(t1.left, t2.right) && isFoldableMirror(t1.right, t2.left);
    }

    public boolean isFoldable(TreeNode root) {
        if (root == null) return true;
        return isFoldableMirror(root.left, root.right);
    }
}