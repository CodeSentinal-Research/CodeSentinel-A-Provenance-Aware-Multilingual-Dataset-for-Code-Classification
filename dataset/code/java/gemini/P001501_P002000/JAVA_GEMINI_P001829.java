class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int largestSmaller(TreeNode root, int key) {
        int ans = -1;
        TreeNode cur = root;

        while (cur != null) {
            if (cur.val < key) {
                ans = cur.val;
                cur = cur.right;
            } else {
                cur = cur.left;
            }
        }
        return ans;
    }
}