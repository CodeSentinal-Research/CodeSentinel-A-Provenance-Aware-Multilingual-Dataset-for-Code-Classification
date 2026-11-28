import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int idx = 0;

    private void inorder(TreeNode node, List<Integer> vals) {
        if (node == null) return;
        inorder(node.left, vals);
        vals.add(node.val);
        inorder(node.right, vals);
    }

    private void preorder(TreeNode node, List<Integer> vals) {
        if (node == null) return;
        node.val = vals.get(idx++);
        preorder(node.left, vals);
        preorder(node.right, vals);
    }

    public TreeNode convertToMinHeap(TreeNode root) {
        List<Integer> vals = new ArrayList<>();
        inorder(root, vals);
        idx = 0;
        preorder(root, vals);
        return root;
    }
}