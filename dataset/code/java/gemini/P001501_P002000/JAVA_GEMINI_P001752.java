import java.util.HashMap;
import java.util.Map;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private Map<Integer, Integer> map = new HashMap<>();

    private void dfs(TreeNode node, int depth) {
        if (node == null) return;
        map.put(node.val, depth);
        dfs(node.left, depth + 1);
        dfs(node.right, depth + 1);
    }

    public Map<Integer, Integer> countAncestors(TreeNode root) {
        map.clear();
        dfs(root, 0);
        return map;
    }
}