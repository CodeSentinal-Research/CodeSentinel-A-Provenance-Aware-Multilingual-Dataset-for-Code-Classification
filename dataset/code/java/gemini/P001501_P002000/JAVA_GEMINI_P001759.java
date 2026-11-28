import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private Map<Integer, Integer> count = new HashMap<>();

    private void dfs(TreeNode node) {
        if (node == null) return;
        count.put(node.val, count.getOrDefault(node.val, 0) + 1);
        dfs(node.left);
        dfs(node.right);
    }

    public int[] findMode(TreeNode root) {
        count.clear();
        dfs(root);
        int maxF = 0;
        for (int v : count.values()) maxF = Math.max(maxF, v);

        List<Integer> list = new ArrayList<>();
        for (Map.Entry<Integer, Integer> e : count.entrySet()) {
            if (e.getValue() == maxF) list.add(e.getKey());
        }

        int[] res = new int[list.size()];
        for (int i = 0; i < list.size(); i++) res[i] = list.get(i);
        return res;
    }
}