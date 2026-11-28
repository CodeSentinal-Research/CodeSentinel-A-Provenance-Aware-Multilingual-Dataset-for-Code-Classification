class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int maxSize = 0;

    static class TreeInfo {
        boolean isComp, isPerf;
        int height, size;
        TreeInfo(boolean c, boolean p, int h, int s) {
            isComp = c; isPerf = p; height = h; size = s;
        }
    }

    private TreeInfo dfs(TreeNode node) {
        if (node == null) return new TreeInfo(true, true, 0, 0);

        TreeInfo l = dfs(node.left);
        TreeInfo r = dfs(node.right);

        int curSize = l.size + r.size + 1;

        if (l.isPerf && r.isComp && l.height == r.height) {
            maxSize = Math.max(maxSize, curSize);
            return new TreeInfo(true, r.isPerf, l.height + 1, curSize);
        }

        if (l.isComp && r.isPerf && l.height == r.height + 1) {
            maxSize = Math.max(maxSize, curSize);
            return new TreeInfo(true, false, l.height + 1, curSize);
        }

        return new TreeInfo(false, false, 0, 0);
    }

    public int largestCompleteSubtree(TreeNode root) {
        maxSize = 0;
        dfs(root);
        return maxSize;
    }
}