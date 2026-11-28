class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int idx = 0;

    private TreeNode build(int[] preorder, int bound) {
        if (idx == preorder.length || preorder[idx] > bound) return null;
        int val = preorder[idx++];
        TreeNode root = new TreeNode(val);
        root.left = build(preorder, val);
        root.right = build(preorder, bound);
        return root;
    }

    public TreeNode bstFromPreorder(int[] preorder) {
        idx = 0;
        return build(preorder, Integer.MAX_VALUE);
    }
}