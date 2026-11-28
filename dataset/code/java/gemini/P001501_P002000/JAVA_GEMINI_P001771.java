import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private Map<Integer, Integer> map = new TreeMap<>();

    private void dfs(TreeNode node, int col) {
        if (node == null) return;
        map.put(col, map.getOrDefault(col, 0) + node.val);
        dfs(node.left, col - 1);
        dfs(node.right, col + 1);
    }

    public List<Integer> verticalSum(TreeNode root) {
        map.clear();
        dfs(root, 0);
        return new ArrayList<>(map.values());
    }
}