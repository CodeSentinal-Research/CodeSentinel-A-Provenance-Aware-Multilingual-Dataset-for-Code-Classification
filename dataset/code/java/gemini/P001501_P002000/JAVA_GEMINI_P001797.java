class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int idx;

    private TreeNode build(int[] postorder, int bound) {
        if (idx < 0 || postorder[idx] < bound) return null;
        int val = postorder[idx--];
        TreeNode root = new TreeNode(val);
        root.right = build(postorder, val);
        root.left = build(postorder, bound);
        return root;
    }

    public TreeNode bstFromPostorder(int[] postorder) {
        idx = postorder.length - 1;
        return build(postorder, Integer.MIN_VALUE);
    }
}