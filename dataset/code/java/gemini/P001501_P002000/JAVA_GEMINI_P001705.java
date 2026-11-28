import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        Deque<Pair> dq = new ArrayDeque<>();
        dq.offer(new Pair(root, 0L));
        long maxWidth = 0;

        while (!dq.isEmpty()) {
            int size = dq.size();
            long minIdx = dq.peekFirst().idx;
            long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                Pair p = dq.pollFirst();
                long curIdx = p.idx - minIdx;
                if (i == 0) first = curIdx;
                if (i == size - 1) last = curIdx;

                if (p.node.left != null) dq.offer(new Pair(p.node.left, 2 * curIdx));
                if (p.node.right != null) dq.offer(new Pair(p.node.right, 2 * curIdx + 1));
            }
            maxWidth = Math.max(maxWidth, last - first + 1);
        }
        return (int)maxWidth;
    }

    static class Pair {
        TreeNode node;
        long idx;
        Pair(TreeNode n, long i) { node = n; idx = i; }
    }
}