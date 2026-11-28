class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int count = 0;

    private void dfs(TreeNode node, Integer parentVal, boolean isInc, boolean isDec) {
        if (node == null) return;
        if (parentVal != null) {
            if (node.val < parentVal) isInc = false;
            if (node.val > parentVal) isDec = false;
        }
        if (node.left == null && node.right == null) {
            if (isInc || isDec) count++;
            return;
        }
        dfs(node.left, node.val, isInc, isDec);
        dfs(node.right, node.val, isInc, isDec);
    }

    public int countMonotonicPaths(TreeNode root) {
        count = 0;
        dfs(root, null, true, true);
        return count;
    }
}