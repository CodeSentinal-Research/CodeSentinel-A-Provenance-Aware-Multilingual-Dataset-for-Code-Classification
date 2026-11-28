import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private void inorder(TreeNode node, List<Integer> vals) {
        if (node == null) return;
        inorder(node.left, vals);
        vals.add(node.val);
        inorder(node.right, vals);
    }

    private TreeNode build(List<Integer> vals, int l, int r) {
        if (l > r) return null;
        // Calculate midpoint to prevent potential overflow
        int mid = l + (r - l) / 2;
        TreeNode node = new TreeNode(vals.get(mid));
        node.left = build(vals, l, mid - 1);
        node.right = build(vals, mid + 1, r);
        return node;
    }

    public TreeNode balanceBST(TreeNode root) {
        List<Integer> vals = new ArrayList<>();
        inorder(root, vals);
        return build(vals, 0, vals.size() - 1);
    }
}