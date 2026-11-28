class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int countNodes(TreeNode root) {
        if (root == null) return 0;
        int lDepth = 0, rDepth = 0;
        TreeNode l = root, r = root;

        while (l != null) {
            lDepth++;
            l = l.left;
        }
        while (r != null) {
            rDepth++;
            r = r.right;
        }

        if (lDepth == rDepth) return (1 << lDepth) - 1;

        return 1 + countNodes(root.left) + countNodes(root.right);
    }
}