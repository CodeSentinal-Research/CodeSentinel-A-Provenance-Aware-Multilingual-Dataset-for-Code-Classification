import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    public List<Integer> bottomView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;

        Map<Integer, Integer> map = new TreeMap<>();
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(root, 0));

        while (!q.isEmpty()) {
            Pair p = q.poll();
            map.put(p.col, p.node.val);
            if (p.node.left != null) q.offer(new Pair(p.node.left, p.col - 1));
            if (p.node.right != null) q.offer(new Pair(p.node.right, p.col + 1));
        }

        for (int v : map.values()) res.add(v);
        return res;
    }

    static class Pair {
        TreeNode node;
        int col;
        Pair(TreeNode n, int c) { node = n; col = c; }
    }
}