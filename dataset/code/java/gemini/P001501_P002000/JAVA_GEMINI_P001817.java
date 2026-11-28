class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int ceilBST(TreeNode root, int key) {
        int ceilVal = -1;
        TreeNode cur = root;

        while (cur != null) {
            if (cur.val == key) {
                return cur.val;
            } else if (cur.val > key) {
                ceilVal = cur.val;
                cur = cur.left;
            } else {
                cur = cur.right;
            }
        }
        return ceilVal;
    }
}