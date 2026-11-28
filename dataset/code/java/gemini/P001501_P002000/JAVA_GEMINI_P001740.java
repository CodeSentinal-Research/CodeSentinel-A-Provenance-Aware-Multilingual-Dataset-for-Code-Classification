import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private List<List<Integer>> res = new ArrayList<>();

    private int dfs(TreeNode node) {
        if (node == null) return -1;
        int height = 1 + Math.max(dfs(node.left), dfs(node.right));
        if (height == res.size()) res.add(new ArrayList<>());
        res.get(height).add(node.val);
        return height;
    }

    public List<List<Integer>> findLeaves(TreeNode root) {
        res.clear();
        dfs(root);
        return res;
    }
}