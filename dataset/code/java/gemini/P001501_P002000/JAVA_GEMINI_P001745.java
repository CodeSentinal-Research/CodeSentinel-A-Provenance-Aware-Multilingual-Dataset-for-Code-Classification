import java.util.HashMap;
import java.util.Map;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private Map<Integer, Integer> heights = new HashMap<>();

    private int dfs(TreeNode node) {
        if (node == null) return -1;
        int h = 1 + Math.max(dfs(node.left), dfs(node.right));
        heights.put(node.val, h);
        return h;
    }

    public Map<Integer, Integer> nodeHeights(TreeNode root) {
        heights.clear();
        dfs(root);
        return heights;
    }
}