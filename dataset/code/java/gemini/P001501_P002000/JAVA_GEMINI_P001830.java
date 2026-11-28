class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int smallestGreater(TreeNode root, int key) {
        int ans = -1;
        TreeNode cur = root;

        while (cur != null) {
            if (cur.val > key) {
                ans = cur.val;
                cur = cur.left;
            } else {
                cur = cur.right;
            }
        }
        return ans;
    }
}