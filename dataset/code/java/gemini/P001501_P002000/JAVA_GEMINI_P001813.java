class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int closestValue(TreeNode root, double target) {
        int closest = root.val;
        TreeNode cur = root;

        while (cur != null) {
            if (Math.abs(cur.val - target) < Math.abs(closest - target) ||
                (Math.abs(cur.val - target) == Math.abs(closest - target) && cur.val < closest)) {
                closest = cur.val;
            }

            if (target < cur.val) {
                cur = cur.left;
            } else {
                cur = cur.right;
            }
        }
        return closest;
    }
}