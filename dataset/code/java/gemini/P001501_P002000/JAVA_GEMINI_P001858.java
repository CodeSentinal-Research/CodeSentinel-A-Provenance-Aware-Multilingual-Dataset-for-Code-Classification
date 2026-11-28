import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    static class NodeDetails {
        TreeNode node;
        long low, high;
        NodeDetails(TreeNode n, long l, long h) { node = n; low = l; high = h; }
    }

    public TreeNode constructBST(int[] levelOrder) {
        if (levelOrder.length == 0) return null;
        TreeNode root = new TreeNode(levelOrder[0]);
        Queue<NodeDetails> q = new LinkedList<>();
        q.offer(new NodeDetails(root, Long.MIN_VALUE, Long.MAX_VALUE));
        int idx = 1;

        while (!q.isEmpty() && idx < levelOrder.length) {
            NodeDetails cur = q.poll();

            if (idx < levelOrder.length && levelOrder[idx] > cur.low && levelOrder[idx] < cur.node.val) {
                cur.node.left = new TreeNode(levelOrder[idx]);
                q.offer(new NodeDetails(cur.node.left, cur.low, cur.node.val));
                idx++;
            }
            if (idx < levelOrder.length && levelOrder[idx] > cur.node.val && levelOrder[idx] < cur.high) {
                cur.node.right = new TreeNode(levelOrder[idx]);
                q.offer(new NodeDetails(cur.node.right, cur.node.val, cur.high));
                idx++;
            }
        }
        return root;
    }
}