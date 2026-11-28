import java.util.HashSet;
import java.util.Set;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private Set<Integer> seen = new HashSet<>();

    private boolean dfs(TreeNode node, int k) {
        if (node == null) return false;
        if (seen.contains(k - node.val)) return true;
        seen.add(node.val);
        return dfs(node.left, k) || dfs(node.right, k);
    }

    public boolean findTarget(TreeNode root, int k) {
        seen.clear();
        return dfs(root, k);
    }
}