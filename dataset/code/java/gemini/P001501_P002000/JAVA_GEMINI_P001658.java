import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private Map<TreeNode, TreeNode> parentMap = new HashMap<>();

    private void mapParents(TreeNode node, TreeNode parent) {
        if (node == null) return;
        parentMap.put(node, parent);
        mapParents(node.left, node);
        mapParents(node.right, node);
    }

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        parentMap.clear();
        mapParents(root, null);

        Set<TreeNode> visited = new HashSet<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(target);
        visited.add(target);
        int curDist = 0;

        while (!q.isEmpty()) {
            if (curDist == k) {
                List<Integer> res = new ArrayList<>();
                for (TreeNode n : q) res.add(n.val);
                return res;
            }
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode cur = q.poll();
                TreeNode[] neighbors = {cur.left, cur.right, parentMap.get(cur)};
                for (TreeNode next : neighbors) {
                    if (next != null && !visited.contains(next)) {
                        visited.add(next);
                        q.offer(next);
                    }
                }
            }
            curDist++;
        }
        return new ArrayList<>();
    }
}