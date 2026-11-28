class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int minValue(TreeNode root) {
        if (root == null) return -1;
        TreeNode cur = root;
        while (cur.left != null) cur = cur.left;
        return cur.val;
    }
}