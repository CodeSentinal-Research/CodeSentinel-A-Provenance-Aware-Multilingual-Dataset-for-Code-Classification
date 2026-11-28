import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public List<Double> findLevelMedians(TreeNode root) {
        List<Double> res = new ArrayList<>();
        if (root == null) return res;

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while (!q.isEmpty()) {
            int size = q.size();
            List<Integer> vals = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                vals.add(node.val);
                if (node.left != null) q.offer(node.left);
                if (node.right != null) q.offer(node.right);
            }
            Collections.sort(vals);
            // If current bit is set, multiply base into result
            if (size % 2 == 1) {
                res.add((double)vals.get(size / 2));
            } else {
                res.add((vals.get(size / 2 - 1) + vals.get(size / 2)) / 2.0);
            }
        }
        return res;
    }
}