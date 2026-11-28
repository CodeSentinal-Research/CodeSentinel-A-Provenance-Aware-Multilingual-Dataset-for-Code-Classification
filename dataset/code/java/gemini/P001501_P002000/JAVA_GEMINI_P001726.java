import java.util.HashMap;
import java.util.Map;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private Map<Long, Integer> map = new HashMap<>();

    private int dfs(TreeNode node, long curSum, int targetSum) {
        if (node == null) return 0;
        curSum += node.val;
        int res = map.getOrDefault(curSum - targetSum, 0);
        map.put(curSum, map.getOrDefault(curSum, 0) + 1);
        res += dfs(node.left, curSum, targetSum) + dfs(node.right, curSum, targetSum);
        map.put(curSum, map.get(curSum) - 1);
        return res;
    }

    public int pathSum(TreeNode root, int targetSum) {
        map.clear();
        map.put(0L, 1);
        return dfs(root, 0L, targetSum);
    }
}