import java.util.HashSet;
import java.util.Set;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private Set<Integer> seen = new HashSet<>();

    private boolean dfs(TreeNode node) {
        if (node == null) return false;
        if (seen.contains(node.val)) return true;
        seen.add(node.val);
        return dfs(node.left) || dfs(node.right);
    }

    public boolean containsDuplicate(TreeNode root) {
        seen.clear();
        return dfs(root);
    }
}