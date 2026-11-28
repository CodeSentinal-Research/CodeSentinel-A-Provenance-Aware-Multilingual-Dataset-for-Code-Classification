import java.util.List;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public TreeNode lcaMultipleBST(TreeNode root, List<TreeNode> nodes) {
        int minVal = Integer.MAX_VALUE, maxVal = Integer.MIN_VALUE;
        for (TreeNode n : nodes) {
            minVal = Math.min(minVal, n.val);
            maxVal = Math.max(maxVal, n.val);
        }

        TreeNode cur = root;
        while (cur != null) {
            if (maxVal < cur.val) {
                cur = cur.left;
            } else if (minVal > cur.val) {
                cur = cur.right;
            } else {
                return cur;
            }
        }
        return null;
    }
}