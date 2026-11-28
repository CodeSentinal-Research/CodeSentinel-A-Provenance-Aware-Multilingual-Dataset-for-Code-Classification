import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private List<Integer> longest = new ArrayList<>();

    private void dfs(TreeNode node, List<Integer> path) {
        if (node == null) return;
        path.add(node.val);
        if (node.left == null && node.right == null) {
            if (path.size() > longest.size()) {
                longest = new ArrayList<>(path);
            }
        } else {
            dfs(node.left, path);
            dfs(node.right, path);
        }
        path.remove(path.size() - 1);
    }

    public List<Integer> longestPath(TreeNode root) {
        longest.clear();
        dfs(root, new ArrayList<>());
        return longest;
    }
}