import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private Map<Integer, Integer> map = new TreeMap<>();

    private void dfs(TreeNode node, int d) {
        if (node == null) return;
        map.put(d, map.getOrDefault(d, 0) + node.val);
        dfs(node.left, d);
        dfs(node.right, d + 1);
    }

    public List<Integer> antiDiagonalSum(TreeNode root) {
        map.clear();
        dfs(root, 0);
        return new ArrayList<>(map.values());
    }
}