import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private void inorder(TreeNode node, int low, int high, List<Integer> res) {
        if (node == null) return;
        if (node.val > low) inorder(node.left, low, high, res);
        if (node.val >= low && node.val <= high) res.add(node.val);
        if (node.val < high) inorder(node.right, low, high, res);
    }

    public List<Integer> rangeSearch(TreeNode root, int low, int high) {
        List<Integer> res = new ArrayList<>();
        inorder(root, low, high, res);
        return res;
    }
}