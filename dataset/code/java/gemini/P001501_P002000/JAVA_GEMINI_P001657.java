import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private TreeNode targetNode = null;
    private Map<TreeNode, TreeNode> parentMap = new HashMap<>();

    private void mapParents(TreeNode node, TreeNode parent, int start) {
        if (node == null) return;
        if (node.val == start) targetNode = node;
        parentMap.put(node, parent);
        mapParents(node.left, node, start);
        mapParents(node.right, node, start);
    }

    public int minTimeToBurn(TreeNode root, int start) {
        parentMap.clear();
        targetNode = null;
        mapParents(root, null, start);

        Set<TreeNode> visited = new HashSet<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(targetNode);
        visited.add(targetNode);
        int time = 0;

        while (!q.isEmpty()) {
            int size = q.size();
            boolean burned = false;
            for (int i = 0; i < size; i++) {
                TreeNode cur = q.poll();
                TreeNode[] neighbors = {cur.left, cur.right, parentMap.get(cur)};
                for (TreeNode next : neighbors) {
                    if (next != null && !visited.contains(next)) {
                        visited.add(next);
                        q.offer(next);
                        burned = true;
                    }
                }
            }
            if (burned) time++;
        }
        return time;
    }
}