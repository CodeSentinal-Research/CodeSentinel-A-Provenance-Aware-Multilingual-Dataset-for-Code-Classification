import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    static class NodeInfo implements Comparable<NodeInfo> {
        int col, row, val;
        NodeInfo(int c, int r, int v) { col = c; row = r; val = v; }
        public int compareTo(NodeInfo o) {
            if (this.col != o.col) return Integer.compare(this.col, o.col);
            if (this.row != o.row) return Integer.compare(this.row, o.row);
            return Integer.compare(this.val, o.val);
        }
    }

    private void dfs(TreeNode node, int row, int col, List<NodeInfo> list) {
        if (node == null) return;
        list.add(new NodeInfo(col, row, node.val));
        dfs(node.left, row + 1, col - 1, list);
        dfs(node.right, row + 1, col + 1, list);
    }

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<NodeInfo> list = new ArrayList<>();
        dfs(root, 0, 0, list);
        Collections.sort(list);

        List<List<Integer>> res = new ArrayList<>();
        int prevCol = Integer.MIN_VALUE;
        List<Integer> curList = null;

        for (NodeInfo info : list) {
            if (info.col != prevCol) {
                if (curList != null) res.add(curList);
                curList = new ArrayList<>();
                prevCol = info.col;
            }
            curList.add(info.val);
        }
        if (curList != null) res.add(curList);

        return res;
    }
}