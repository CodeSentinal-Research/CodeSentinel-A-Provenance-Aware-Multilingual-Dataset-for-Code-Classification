class TreeNode {
    int val;
    TreeNode left, right;
    boolean isThreaded;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public boolean verifyThreaded(TreeNode root) {
        if (root == null) return true;
        TreeNode cur = root;
        while (cur.left != null) cur = cur.left;

        int count = 0;
        while (cur != null) {
            count++;
            if (cur.isThreaded) {
                cur = cur.right;
            } else {
                cur = cur.right;
                while (cur != null && cur.left != null) cur = cur.left;
            }
        }
        return count > 0;
    }
}