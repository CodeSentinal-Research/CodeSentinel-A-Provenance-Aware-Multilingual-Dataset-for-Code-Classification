import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private TreeNode targetNode = null;
    private Map<TreeNode, TreeNode> parentMap = new HashMap<>();

    private void dfs(TreeNode node, TreeNode parent, int k) {
        if (node == null) return;
        if (node.val == k) targetNode = node;
        parentMap.put(node, parent);
        dfs(node.left, node, k);
        dfs(node.right, node, k);
    }

    public int findClosestLeaf(TreeNode root, int k) {
        parentMap.clear();
        targetNode = null;
        dfs(root, null, k);

        Set<TreeNode> visited = new HashSet<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(targetNode);
        visited.add(targetNode);

        while (!q.isEmpty()) {
            TreeNode curr = q.poll();
            if (curr.left == null && curr.right == null) return curr.val;

            TreeNode[] neighbors = {curr.left, curr.right, parentMap.get(curr)};
            for (TreeNode next : neighbors) {
                if (next != null && !visited.contains(next)) {
                    visited.add(next);
                    q.offer(next);
                }
            }
        }
        return -1;
    }
}