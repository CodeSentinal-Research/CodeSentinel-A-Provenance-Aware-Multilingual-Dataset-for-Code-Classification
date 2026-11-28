class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int maxValue(TreeNode root) {
        if (root == null) return -1;
        TreeNode cur = root;
        while (cur.right != null) cur = cur.right;
        return cur.val;
    }
}