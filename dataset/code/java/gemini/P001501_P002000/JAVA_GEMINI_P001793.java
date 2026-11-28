class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public TreeNode inorderPredecessor(TreeNode root, TreeNode p) {
        TreeNode pred = null;
        TreeNode cur = root;
        while (cur != null) {
            if (cur.val < p.val) {
                pred = cur;
                cur = cur.right;
            } else {
                cur = cur.left;
            }
        }
        return pred;
    }
}