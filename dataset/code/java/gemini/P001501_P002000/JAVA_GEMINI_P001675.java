import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private void dfs(TreeNode node, int d, Map<Integer, List<Integer>> map) {
        if (node == null) return;
        map.computeIfAbsent(d, k -> new ArrayList<>()).add(node.val);
        dfs(node.left, d + 1, map);
        dfs(node.right, d, map);
    }

    public List<Integer> diagonalTraversal(TreeNode root) {
        Map<Integer, List<Integer>> map = new TreeMap<>();
        dfs(root, 0, map);
        List<Integer> res = new ArrayList<>();
        for (List<Integer> list : map.values()) {
            res.addAll(list);
        }
        return res;
    }
}