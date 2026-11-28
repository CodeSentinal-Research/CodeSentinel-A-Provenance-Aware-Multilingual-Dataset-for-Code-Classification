import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private Map<String, Integer> count = new HashMap<>();
    private List<TreeNode> res = new ArrayList<>();

    private String serialize(TreeNode node) {
        if (node == null) return "#";
        String serial = node.val + "," + serialize(node.left) + "," + serialize(node.right);
        count.put(serial, count.getOrDefault(serial, 0) + 1);
        if (count.get(serial) == 2) {
            res.add(node);
        }
        return serial;
    }

    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        count.clear();
        res.clear();
        serialize(root);
        return res;
    }
}