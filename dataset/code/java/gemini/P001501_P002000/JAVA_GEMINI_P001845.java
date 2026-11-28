import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private TreeNode insert(TreeNode root, int val) {
        if (root == null) return new TreeNode(val);
        if (val < root.val) root.left = insert(root.left, val);
        else root.right = insert(root.right, val);
        return root;
    }

    private String serializeShape(TreeNode root) {
        if (root == null) return "#";
        return "(" + serializeShape(root.left) + "," + serializeShape(root.right) + ")";
    }

    public int numDistinctShapes(int[][] seqs) {
        Set<String> shapes = new HashSet<>();
        for (int[] seq : seqs) {
            TreeNode root = null;
            for (int x : seq) root = insert(root, x);
            shapes.add(serializeShape(root));
        }
        return shapes.size();
    }
}