import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public List<Integer> findCousins(TreeNode root, int targetVal) {
        List<Integer> res = new ArrayList<>();
        if (root == null || root.val == targetVal) return res;

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        boolean found = false;

        while (!q.isEmpty() && !found) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode cur = q.poll();
                if ((cur.left != null && cur.left.val == targetVal) || 
                    (cur.right != null && cur.right.val == targetVal)) {
                    found = true;
                } else {
                    if (cur.left != null) q.offer(cur.left);
                    if (cur.right != null) q.offer(cur.right);
                }
            }
        }

        if (found) {
            for (TreeNode n : q) res.add(n.val);
        }
        return res;
    }
}