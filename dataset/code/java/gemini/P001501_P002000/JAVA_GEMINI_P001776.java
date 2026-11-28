import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public boolean isEveryLevelPalindromic(TreeNode root) {
        if (root == null) return true;
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
            for (int l = 0, r = size - 1; l < r; l++, r--) {
                if (!vals.get(l).equals(vals.get(r))) return false;
            }
        }
        return true;
    }
}