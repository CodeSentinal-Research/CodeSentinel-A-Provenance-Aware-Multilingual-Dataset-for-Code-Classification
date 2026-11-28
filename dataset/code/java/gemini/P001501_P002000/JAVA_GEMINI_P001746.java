import java.util.HashMap;
import java.util.Map;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private Map<Integer, Integer> depths = new HashMap<>();

    private void dfs(TreeNode node, int d) {
        if (node == null) return;
        depths.put(node.val, d);
        dfs(node.left, d + 1);
        dfs(node.right, d + 1);
    }

    public Map<Integer, Integer> nodeDepths(TreeNode root) {
        depths.clear();
        dfs(root, 0);
        return depths;
    }
}