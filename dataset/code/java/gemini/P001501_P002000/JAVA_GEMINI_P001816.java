class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int floorBST(TreeNode root, int key) {
        int floorVal = -1;
        TreeNode cur = root;

        while (cur != null) {
            if (cur.val == key) {
                return cur.val;
            } else if (cur.val < key) {
                floorVal = cur.val;
                cur = cur.right;
            } else {
                cur = cur.left;
            }
        }
        return floorVal;
    }
}