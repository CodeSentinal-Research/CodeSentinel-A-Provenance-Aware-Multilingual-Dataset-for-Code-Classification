import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int maxAdjacentLevelDiff(TreeNode root) {
        if (root == null) return 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        List<Long> levelSums = new ArrayList<>();

        while (!q.isEmpty()) {
            int size = q.size();
            long curSum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                curSum += node.val;
                if (node.left != null) q.offer(node.left);
                if (node.right != null) q.offer(node.right);
            }
            levelSums.add(curSum);
        }

        long maxDiff = 0;
        for (int i = 1; i < levelSums.size(); i++) {
            maxDiff = Math.max(maxDiff, Math.abs(levelSums.get(i) - levelSums.get(i - 1)));
        }
        return (int)maxDiff;
    }
}